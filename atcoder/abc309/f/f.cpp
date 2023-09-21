#include <bits/stdc++.h>
// #include <bits/extc++.h>
 
using namespace std;
// using namespace __gnu_pbds;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>,
// 			      rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
 
using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
 
using vi = vector<int>;
using vll = vector<ll>;
#define pb emplace_back
#define sz(x) int(x.size())
 
using graph_t = vector<vi>;
using tii = tuple<int, int, int>;
 
const int INF = 0x3f3f3f3f;
 
template <typename T>
struct seg_t {
  seg_t(int _n, T _zero = T())
    : n(_n), tree(2 * n, _zero), zero(_zero) {}
 
  void build(std::vector<T> const& arr) {
    assert(sz(arr) == n);
 
    for (int i = 0; i < n; ++i)
      tree[i + n] = arr[i];
 
    for (int i = n - 1; i > 0; --i)
      pull(i);
  }
 
  void update(int i, T x) {
    tree[i += n] = x;
    for (i /= 2; i; i /= 2) pull(i);
  }
 
  T query(int l, int r) {
    T ra = zero, rb = zero;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) ra = ra + tree[l++];
      if (r & 1) rb = tree[--r] + rb;
    }
    return ra + rb;
  }
 
private:
  void pull(int i) { tree[i] = tree[2 * i] + tree[2 * i + 1]; }
 
  int n;
  vector<T> tree;
  T zero;
};
 
struct node_t {
  int x = INF;
  node_t operator+(node_t const& r) {
    return { min(x, r.x) };
  }
};
 
const int N = 2e5 + 5;
int tr[N * 4];
 
#define lc (u * 2 + 1)
#define rc (u * 2 + 2)
#define mid (l + (r - l) / 2)
 
void upd(int u, int l, int r, int x, int val) {
    if (r - l == 1) {
        tr[u] = std::min(tr[u], val);
    } else {
        if (x < mid) {
            upd(lc, l, mid, x, val);
        } else {
            upd(rc, mid, r, x, val);
        }
        tr[u] = std::min(tr[lc], tr[rc]);
    }
}
 
int query(int u, int l, int r, int lo, int hi) {
    if (lo <= l and r <= hi) {
        return tr[u];
    } else if (r <= lo or hi <= l or r - l == 1) {
        return INF;
    } else {
        return std::min(query(lc, l, mid, lo, hi), query(rc, mid, r, lo, hi));
    }
}
 
void solve() {
  int n;
  cin >> n;
 
  std::fill(tr, tr + N * 4, INF);
 
  vector<array<int, 3>> boxes(n);
  vector<int> xx(n);
 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> boxes[i][j];
    }
 
    sort(boxes[i].begin(), boxes[i].end());
    xx[i] = boxes[i][1];
  }
 
  auto cmp = [](array<int, 3> const& a, array<int, 3> const& b) {
    return mp(a[0], -a[1]) < mp(b[0], -b[1]);
  };
 
  sort(boxes.begin(), boxes.end(), cmp);
	
 
  // coordinate compression
  map<int, int> coord;
  sort(xx.begin(), xx.end());
 
  for (int i = 0; i < n; ++i) {
    coord[xx[i]] = i;
  }
	seg_t<node_t> seg(coord.size(), {INF});
	vector<node_t> nodes;
	for (int i = 0; i < n; i++) {
		
	}
 
  for (int i = 0; i < n; ++i) {
    boxes[i][1] = coord.at(boxes[i][1]);
  }
 
  for (auto [x, y, z] : boxes) {
    if (query(0, 0, n, 0, y) < z) {
      cout << "Yes\n";
      return;
    }
 
    upd(0, 0, n, y, z);
  }
 
  cout << "No\n";
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}