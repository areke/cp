#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second

#define pb emplace_back
#define sz(x) int(x.size())

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

  explicit lazy_seg_t(int n, T zero = {1, 1, 1, true}, U noop = U())
    : n(n), zero(zero), noop(noop), tree(4 * n) {
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
  ll x;
  long long tl, tr;
  bool identity = false;

  node_t operator+(node_t const& other) {
    if (identity) return other;
    if (other.identity) return *this;
    return { x + other.x, tl, other.tr, identity };
  }
};

struct update_t {
  
	int type = 0;
	ll x = 0;

  node_t operator()(node_t const& node) const {
		return { node.x + x * ((node.tr + 2) * (node.tr + 1) / 2 - (node.tl + 1) * node.tl / 2), node.tl, node.tr, node.identity};
  }

  update_t operator+(update_t const& u) {
    return { type, x + u.x };
  }
};



struct update2_t {
  
	int type = 0;
	ll x = 0;

  node_t operator()(node_t const& node) const {
		return { node.x + x * (node.tr - node.tl + 1), node.tl, node.tr, node.identity};
  }

  update2_t operator+(update2_t const& u) {
    return { type, x + u.x };
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vector<node_t> leaves(n, {0, 0, 0, 0});

  vector<node_t> leaves2(n, {0, 0, 0, 0});
  for (int i = 0; i < n; ++i) {
    cin >> leaves[i].x;
    leaves[i].tl = i;
    leaves[i].tr = i;
		leaves2[i].x = 0;
		leaves2[i].tl = i;
		leaves2[i].tr = i;
		
  }

  lazy_seg_t<node_t, update_t> seg(n);
  seg.build(leaves);


  lazy_seg_t<node_t, update2_t> seg2(n);
	seg2.build(leaves2);


  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a, --b;
    if (t == 2){
      cout << seg.query(a, b).x + seg2.query(a, b).x << endl;
		}
    else {
      seg.update(a, b, {1, 1 });
			seg2.update(a, b, {0, -a});
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}