#include <bits/stdc++.h>
using namespace std;


using ll = long long;

using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
#define sz(x) int(x.size())

const int MAX_N = 2e5 + 1;

const int INF = 1e9 + 5;


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

  explicit lazy_seg_t(int _n, T _zero = T(), U _noop = U())
    : n(_n), zero(_zero), noop(_noop), tree(4 * n) {
    k = 1, height = 1;
    while (k < n)
      k <<= 1, ++height;
  }

  void build(std::vector<T> const& arr) {
    assert(sz(arr) == n);
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

  void point_update(int i, T const& x) {
    i += k;
    propagate(i);
    tree[i].x = x;
    rebuild(i);
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
  ll x, k;

  node_t operator+(node_t const& other) {
    return { x + other.x, k + other.k};
  }
};

struct update_t {
  ll x;

  node_t operator()(node_t const& node) const {
		return {x * node.k + node.x, node.k };
  }

  update_t operator+(update_t const& u) {
    return { x + u.x };
  }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int q, d;
	cin >> q >> d;
	set<int> s;
	lazy_seg_t<node_t, update_t> seg(MAX_N);
	long long res = 0;

	while (q--) {
		int x;
		cin >> x;
		if (s.find(x) != s.end()) {
			seg.update(max(1, x - d), x - 1, {-1});
			long long delta = seg.query(max(0, x - d), x- 1).x;
			long long cnt = seg.query(min(x + 1, MAX_N - 1), min(x + d, MAX_N - 1)).k;
			
			res -= cnt * (cnt - 1) / 2; 
			res -= delta;
			seg.point_update(x, {0, 0});
			s.erase(x);
		} else {
			long long delta = seg.query(max(0, x - d), x- 1).x;
			seg.update(max(1, x - d), x - 1, {1});
			long long cnt = seg.query(min(x + 1, MAX_N - 1), min(x + d, MAX_N - 1)).k;
			res += cnt * (cnt - 1) / 2;
			res += delta;
			seg.point_update(x, {cnt, 1});
			s.insert(x);
		}

		
		cout << res << endl;

	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
