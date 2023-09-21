#include <bits/stdc++.h>

#define pb emplace_back
#define N 100005
 
using ll = long long;
 
ll d[N], c[N], dp[N], n;
bool q_term[N], vis[N], q_cycle[N];
 
void dfs(ll u, std::vector<std::vector<ll>> &cycles, std::set<int> & path) {
 
  while (true) {
    if (path.find(u) != path.end()) break;
    if (vis[u]) return;
 
    vis[u] = true;
		path.insert(u);
    u = d[u];
  }
 
  cycles.pb();
  auto &cycle = cycles.back();
  ll v = u;
 
  do {
    q_cycle[v] = true;
    cycle.pb(v);
    v = d[v];
  } while (v != u);
}
 
void prop_path(ll u) {
  while (!q_cycle[u] && !vis[u]) {
    vis[u] = true;
    dp[d[u]] += c[u];
    u = d[u];
  }
}
 
ll cycle_cost(std::vector<ll> const& cycle) {
  ll tot = 0, ret = LLONG_MAX, m = cycle.size();
 
  for (ll i = 0; i < m; ++i) {
    ll u = cycle[i], pred = cycle[(i - 1 + m) % m];
    tot += std::max(0ll, c[u] - dp[u] - c[pred]);
  }
 
  for (ll i = 0; i < m; ++i) {
    ll u = cycle[i], pred = cycle[(i - 1 + m) % m];
    ll cost = tot - std::max(0ll, c[u] - dp[u] - c[pred]) + std::max(0ll, c[u] - dp[u]);
    // std::cout << u << ": " << ret << " " << cost << " " << cost << std::endl;
    ret = std::min(ret, cost);
  }
 
  // std::cout << "cycle cost: " << ret << std::endl;
  return ret;
}
 
void solve(ll t) {
  std::cin >> n;
 
  std::vector<ll> terms;
  std::vector<std::vector<ll>> cycles;
 
  std::fill(q_term, q_term + n, true);
  for (ll i = 0; i < n; ++i) {
    std::cin >> d[i];
    q_term[--d[i]] = false;
  }
 
  for (ll i = 0; i < n; ++i)
    std::cin >> c[i];
 
  // extract list of terminal nodes
  for (ll i = 0; i < n; ++i)
    if (q_term[i])
      terms.pb(i);
 
  // std::cout << "terms: ";
  // for (auto u : terms)
  //   std::cout << u << " ";
  // std::cout << std::endl;
 
  // dfs on each terminal node to find cycles
  std::fill(q_cycle, q_cycle + n, false);
  std::fill(vis, vis + n, false);
	
  for (ll u = 0; u < n; ++u) {
		std::set<int> path;
    dfs(u, cycles, path);
	}
 
  // std::cout << "cycles: " << std::endl;
  // for (auto const& cycle : cycles) {
  //   for (auto u : cycle)
  //     std::cout << u << " ";
  //   std::cout << std::endl;
  // }
 
  // std::cout << "q_cycle: ";
  // for (ll u = 0; u < n; ++u)
  //   if (q_cycle[u])
  //     std::cout << u << " ";
  // std::cout << std::endl;
 
  // compute costs for paths
  std::fill(dp, dp + n, 0ll);
  std::fill(vis, vis + n, false);
  for (ll u : terms)
    prop_path(u);
 
  // std::cout << "dp: ";
  // for (ll u = 0; u < n; ++u)
  //   std::cout << dp[u] << " ";
  // std::cout << std::endl;
 
  // compute cycle node costs
  ll ret = 0;
 
  // compute non-cycle node costs
  for (ll u = 0; u < n; ++u)
    if (!q_cycle[u]) {
      ll cost = std::max(c[u] - dp[u], 0ll);
      ret += cost;
      // std::cout << u << ": " << cost << std::endl;
    }
 
  for (auto const& cycle : cycles)
    ret += cycle_cost(cycle);
 
  std::cout << "Case #" << t << ": " << ret << std::endl;
}
 
int main() {
  ll T;
  std::cin >> T;
  for (ll t = 1; t <= T; ++t)
    solve(t);
}