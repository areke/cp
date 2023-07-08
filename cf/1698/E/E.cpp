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
 
#define pb emplace_back
#define sz(x) int(x.size())
 
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
 
const int mod = 998244353; 
 
struct mint {
  ll x;
 
  mint() : x(0) {}
 
  mint(ll _x) {
    _x %= mod;
    if (_x < 0) _x += mod;
    x = _x;
  }
 
  mint &operator+=(mint const& a) {
    x += a.x;
    if (x >= mod) x -= mod;
    return *this;
  }
 
  mint &operator-=(mint const& a) {
    x += mod - a.x;
    if (x >= mod) x -= mod;
    return *this;
  }
 
  mint &operator*=(mint const& a) {
    x = x * 1ll * a.x % mod;
    return *this;
  }
 
  mint pow(ll k) const {
    mint ret(1);
    mint a(*this);
    while (k) {
      if (k & 1) ret *= a;
      a *= a;
      k >>= 1;
    }
 
    return ret;
  }
 
  mint inv() const {
    return pow(mod - 2);
  }
 
  inline mint &operator/= (mint const& a) { return *this *= a.inv(); }
  inline mint operator+(mint const& a) const { return mint(*this) += a; }
  inline mint operator-(mint const& a) const { return mint(*this) -= a; }
  inline mint operator*(mint const& a) const { return mint(*this) *= a; }
  inline mint operator/(mint const& a) const { return mint(*this) /= a; }
 
  bool operator==(mint const& a) const { return x == a.x; }
  bool operator!=(mint const& a) const { return x != a.x; }
  bool operator<(mint const& a) const { return x < a.x; }
  friend ostream &operator<<(ostream &os, mint const& a);
  friend istream &operator>>(istream &is, mint &a);
};
 
ostream &operator<<(ostream &os, mint const& a) { return os << a.x; }
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
 
struct mfactorial {
  vector<mint> fact, fact_inv;
  mfactorial(int n) : fact(n + 1), fact_inv(n + 1) {
    fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = 1;
 
    for (int i = 2; i <= n; ++i) {
      fact[i] = fact[i - 1] * i;
      fact_inv[i] = fact_inv[i - 1] * mint(i).inv();
    }
  }
 
  inline mint f(int k) { return fact[k]; }
  inline mint inv(int k) { return fact_inv[k]; }
  inline mint binom(int n, int k) {
    return (n < k || k < 0) ? 0 : fact[n] * fact_inv[k] * fact_inv[n - k];
  }
};
 
void solve() {
  int n, s;
  cin >> n >> s;
 
  vector<pii> x(n + 1, {0, 0});
  for (int i = 1; i <= n; ++i)
    cin >> x[i].xx;
  for (int i = 1; i <= n; ++i)
    cin >> x[i].yy;
 
  sort(x.begin(), x.end());
 
  vector<int> pos(n + 1, -1);
  vector<int> used(n + 1, 0);
 
  for (int i = 1; i <= n; ++i)
    if (x[i].yy != -1)
      pos[x[i].yy] = i;
 
  mint ret = 1;
  int cnt = 0;
 
  for (int i = 1; i <= min(1 + s - 1, n); ++i)
    if (x[i].yy == -1) ++cnt;
 
  for (int i = 1; i <= n; ++i) {
    if (i + s <= n && x[i + s].yy == -1) ++cnt;
    
    int mult = 1;
    if (pos[i] != -1 && pos[i] - i > s)
      mult = 0;
    else if (pos[i] == -1) {
      mult = cnt;
			cnt--;
		}
 
 
    ret *= mult;
  }
 
  cout << ret << '\n';
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}