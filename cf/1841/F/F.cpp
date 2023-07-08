#include <bits/stdc++.h>
// #include <bits/extc++.h>
 
using namespace std;
// using namespace __gnu_pbds;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>,
// 			      rb_tree_tag, tree_order_statistics_node_update>;
 
// using ll = long long;
 
using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
 
using ll = long long;
 
using vi = vector<int>;
using vll = vector<ll>;
#define pb emplace_back
#define sz(x) int(x.size())
 
using graph_t = vector<vi>;
const int INF = 0x3f3f3f3f;
 
#pragma GCC diagnostic ignored "-Wpedantic"
using bi = __int128;
#pragma GCC diagnostic pop
 
std::ostream& operator<<(std::ostream& os, bi x) {
  vector<int> ret;
 
  if (x == 0) ret.pb(0);
  while (x) {
    ret.pb(x % 10);
    x /= 10;
  }
 
  reverse(ret.begin(), ret.end());
 
  for (int i = 0; i < sz(ret); ++i)
    os << ret[i];
 
  return os;
}
 
template <typename T = bi>
struct vector_t {
  T x = 0, y = 0;
 
  vector_t() {}
  vector_t(T _x, T _y) : x(_x), y(_y) {}
 
  inline void operator+=(vector_t const& o) { x += o.x, y += o.y; }
  inline void operator-=(vector_t const& o) { x -= o.x, y -= o.y; }
  inline bool origin() const { return x == 0 && y == 0; }
  inline int half() const {
    if (origin()) return -1;
    if (y < 0 || (y == 0 && x < 0)) return 1;
    return 0;
  }
 
  inline T sq_norm() const { return x * x + y * y; }
  inline T cross(vector_t const& o) const { return x * o.y - y * o.x; }
  inline T inner(vector_t const& o) const { return x * o.x + y * o.y; }
 
  inline bool parallel(vector_t const& o) const {
    return inner(*this) * inner(o) == sq_norm() * o.sq_norm();
  }
 
  bool operator<(vector_t const& o) {
    if (half() != o.half()) return half() < o.half();
    return cross(o) > 0;
  }
};
 
const int N = 3e5 + 5;
vector_t<> pts[N * 2];
 
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
 
    if (a - b == 0 && c - d == 0) {
      --i, --n;
      continue;
    }
 
    pts[i] = vector_t<>(a - b, c - d);
  }
 
  sort(pts, pts + n);
 
  // this allows us to radial sweep without worrying about boundaries
  for (int i = 0; i < n; ++i)
    pts[n + i] = pts[i];
 
  vector_t<> cur;
  bi ret = 0;
 
  for (int l = 0, r = 0; l <= n; ++l) {
    while (r < l + n && (pts[l].cross(pts[r]) > 0 || pts[l].parallel(pts[r]))) {
      cur += pts[r++];
      ret = max(ret, cur.sq_norm());
    }
 
    cur -= pts[l];
    ret = max(ret, cur.sq_norm());
  }
 
  cout << ret << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}