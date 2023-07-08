#include <bits/stdc++.h>
using namespace std;

// T is a monoid and U are endomorphisms (T -> T)
template <typename T, typename U>
struct lazy_seg_t {
  struct internal_node {
    T x;
    U f;
    bool stale;
  };

  int n, k, height;
  T zero;
  U noop;

  vector<internal_node> tree;

  explicit lazy_seg_t(int n, T zero = T(), U noop = U())
    : n(n), zero(zero), noop(noop), tree(4 * n) {
    k = 1, height = 1;
    while (k < n)
      k <<= 1, ++height;
  }

  void build(std::vector<T> const& arr) {
    for (int i = 0; i < n; ++i)
      tree[i + k].x = arr[i];

    for (int i = k - 1; i > 0; --i)
      tree[i].x = tree[2 * i].x + tree[2 * i + 1].x;
  }

  void apply(int i, U const& f) {
    tree[i].x = f(tree[i].x);
    if (i < k) {
      tree[i].f = tree[i].f + f;
      tree[i].stale = true;
    }
  }

  void rebuild(int i) {
    for (int u = i / 2; u; u /= 2) {
      T comb = tree[2 * u].x + tree[2 * u + 1].x;
      tree[u].x = tree[u].f(comb);
    }
  }

  void propagate(int i) {
    for (int h = height; h > 0; --h) {
      int u = i >> h;
      if (tree[u].stale) {
        apply(2 * u, tree[u].f);
        apply(2 * u + 1, tree[u].f);
        tree[u].f = noop;
        tree[u].stale = false;
      }
    }
  }

  void update(int i, int j, U const& u) {
    i += k, j += k;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, u);
      if ((r & 1) == 0) apply(r--, u);
    }

    rebuild(i), rebuild(j);
  }

  void point_update(int i, T const& x) {
    i += k;
    propagate(i);
    tree[i].x = x;
    rebuild(i);
  }

  T query(int i, int j) {
    i += k, j += k;
    propagate(i), propagate(j);

    T l = zero, r = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) l = l + tree[i++].x;
      if ((j & 1) == 0) r = tree[j--].x + r;
    }

    return l + r;
  }
};

struct node_t {
  long long x;

  node_t operator+(node_t const& other) {
    return { max(x, other.x) };
  }
};

struct update_t {
  long long x;

  node_t operator()(node_t const& node) const {
    return { x + node.x };
  }

  update_t operator+(update_t const& u) {
    return { x + u.x };
  }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k, a;
	cin >> n >> k >> a;
	vector<vector<pair<long long, long long> > > v(k + 1);
	for (int i = 0; i < n; i++) {
		long long x, y, c;
		cin >> x >> y >> c;
		v[k - y].push_back({x, c});
	}

	for (int i = 0; i <= k; i++) {
		sort(v[i].begin(), v[i].end());
	}

  vector<node_t> leaves(k + 1, {0});
  
  for (int i = 0; i < k + 1; ++i) {
    cin >> leaves[i].x;
  }

  vector<long long> dp(k + 1, 0);
  lazy_seg_t<node_t, update_t> seg(k + 1);
  seg.build(leaves);
  long long tot = 0;
	for (int i = 1; i <= k; i++) {
    seg.update(0, i - 1, {-a});
    
		for (auto &[x, c] : v[i]) {
			seg.update(0, x, {c});
      tot += c;
		}
    dp[i] = max(dp[i - 1], seg.query(0, i).x);
    seg.point_update(i, {dp[i]});
	}
  tot -= max(0LL, dp[k]);
  cout << tot << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
