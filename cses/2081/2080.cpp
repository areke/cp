#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second
 
#define pb emplace_back
#define sz(x) int(x.size())
 
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;
 
vector<int> graph[N];
ll ret = 0;
int st[N], cnt[N], mx, n, k;
bool vis[N];
 
int dfs1(int u, int par = -1) {
  st[u] = 1;
  for (int v : graph[u]) {
    if (v == par || vis[v]) continue;
    st[u] += dfs1(v, u);
  }
  return st[u];
}
 
int dfs2(int desired, int u, int par = -1) {
  for (int v : graph[u]) {
    if (v == par || vis[v]) continue;
    if (st[v] >= desired / 2)
      return dfs2(desired, v, u);
  }
  return u;
}
 
void dfs3(int u, int par, int depth, bool increment) {
  if (depth > k) return;
 
  mx = max(mx, depth + 1);
 
  if (increment) cnt[depth]++;
  else ret += cnt[k - depth];
 
  for (int v : graph[u]) {
    if (v == par || vis[v]) continue;
    dfs3(v, u, depth + 1, increment);
  }
}
 
void centroid_decomposition(int u) {
  int sz = dfs1(u);
  if (sz < k) return;
  int centroid = dfs2(sz, u);
 
  // remove the centroid and recurse on the resulting subtrees
  vis[centroid] = true;
 
  mx = 1;
  cnt[0] = 1;
 
  for (int v : graph[centroid]) {
    if (vis[v]) continue;
 
    dfs3(v, centroid, 1, false);
    dfs3(v, centroid, 1, true);
  }
 
  memset(cnt, 0, mx * sizeof(int));
 
  for (int v : graph[centroid]) {
    if (vis[v]) continue;
    centroid_decomposition(v);
  }
}
 
void solve() {
  cin >> n >> k;
 
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
 
  centroid_decomposition(0);
  cout << ret << endl;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
 