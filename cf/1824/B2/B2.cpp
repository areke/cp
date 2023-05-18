#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
using ll = long long;
 
using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
 
#define pb emplace_back
#define sz(x) int(x.size())
 
const int INF = 1e9 + 5;
using graph_t = vector<vector<int>>;
 
const int mod = 1e9 + 7;
 
// template <int mod = mod>
struct mint {
  int x;
 
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
    assert(x != 0);
    int t = x;
    int ret = 1;
    while (t != 1) {
      int z = mod / t;
      ret = ret * 1ll * (mod - z) % mod;
      t = mod - t * z;
    }
    return ret;
  }
 
  inline mint &operator/= (mint const& a) { return *this *= a.inv(); }
  inline mint operator+(mint const& a) const { return mint(*this) += a; }
  inline mint operator-(mint const& a) const { return mint(*this) -= a; }
  inline mint operator*(mint const& a) const { return mint(*this) *= a; }
  inline mint operator/(mint const& a) const { return mint(*this) /= a; }
 
  bool operator==(mint const& a) const { return x == a.x; }
  bool operator!=(mint const& a) const { return x != a.x; }
  bool operator<(mint const& a) const { return x < a.x; }
};
 
 
struct mfactorial {
  vector<mint> fact, fact_inv;
  mfactorial(int n) : fact(n + 1 + 1), fact_inv(n + 1) {
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

mfactorial f(2e5 + 1);


void dfs1(int u, int par, graph_t const& graph, vector<int> &st) {
  st[u] = 1;
  for (int v : graph[u])
    if (v != par) {
      dfs1(v, u, graph, st);
      st[u] += st[v];
    }
}
 
void dfs2(int u, int k, int par, graph_t const& graph, vector<int> const& st, mint &ret) {
  for (int v : graph[u])
    if (v != par) {
      dfs2(v, k, u, graph, st, ret);
      ret += f.binom(st[v], k / 2) * f.binom((sz(graph) - st[v]), k / 2);
    }
}
 
void solve() {
  int n, k;
  cin >> n >> k;
 
  graph_t graph(n);
 
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
 
  if (k % 2 == 1) {
    cout << 1 << endl;
    return;
  }
 
 
  vector<int> st(n);
  dfs1(0, -1, graph, st);
 
  mint ret = 0;
  dfs2(0, k, -1, graph, st, ret);
 
 
  ret += f.binom(n, k);
  ret /= f.binom(n, k);
 
  cout << ret.x << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  solve();
}