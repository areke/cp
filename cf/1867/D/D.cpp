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
 
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
 
int b[N];
 
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    --b[i];
  }
 
  if (k == 1) {
    // special case: require array of fixed points
    for (int i = 0; i < n; ++i) {
      if (b[i] != i) {
	cout << "NO\n";
	return;
      }
    }
 
    cout << "YES\n";
    return;
  }
 
  vector<int> dp(n, -1);
  bool found = false;
 
  for (int i = 0; i < n; ++i) {
    if (dp[i] != -1) continue;
 
    int x = i;
    dp[x] = 0;
 
    while (true) {
      if (dp[b[x]] != -1) {
        break;
      }
 
      dp[b[x]] = dp[x] + 1;
      x = b[x];
    }
 
    int m = dp[x] - dp[b[x]] + 1;
 
    // cout << x << " " << m << endl;
    if (abs(m) != k) {
      cout << "NO\n";
      return;
    }
 
    if (m == k)
      found = true;
  }
 
  if (found) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}