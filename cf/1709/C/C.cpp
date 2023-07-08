#include <bits/stdc++.h>
#include <bits/extc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>,
// 			      rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
 
using pii = pair<ll, ll>;
#define mp make_pair
#define xx first
#define yy second
 
#define pb emplace_back
#define sz(x) ll(x.size())
 
const ll INF = 0x3f3f3f3f;
const ll N = 2e5 + 5;
 
void solve() {
  string s;
  cin >> s;
  ll n = sz(s);
 
  ll st = 0, cnt = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '(') ++st;
    else if (s[i] == ')') --st;
    else {
      if (st == 0) ++st;
      else ++cnt;
    }
 
    if (st < 0) {
      --cnt;
      ++st;
    }
 
    assert(st >= 0);
  }
 
  cnt -= st;
  assert(cnt >= 0);
	cout << cnt << " " << st << endl;
 
  if (cnt) {
    assert(cnt > 1);
    cout << "NO\n";
  } else
    cout << "YES\n";
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll t;
  cin >> t;
  while (t--) solve();
}
