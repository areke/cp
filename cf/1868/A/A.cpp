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

int mex(vector<vector<int>> const& x, int n, int m) {
  int ret = 0;
  set<int> t;
  for (int i = 0; i < m; ++i) {
    int mx = 0;
    set<int> s;
    for (int j = 0; j < n; ++j) {
      s.insert(x[j][i]);
      
    }
    for (int j = 0; j < n + 1; j++) {
      if (!s.count(j)) {
        mx = j;
        break;
      }
    }
    t.insert(mx);
  }
  for (int j = 0; j < m + 1; j++) {
    if (!t.count(j)) return j;
  }
  return -1;

}

void solve() {
  int n, m;
  cin >> n >> m;


  vector<vector<int>> ret(n, vector<int>(m, 0));
  
  int offset = m - 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ret[i][j] = (offset + j) % m;
    }

    offset = (offset + 1) % m;
    if (offset == 0) offset = 1;
  }

  cout << mex(ret, n, m) << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ret[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}