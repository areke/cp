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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
using ll = long long;
 
using pii = pair<int, int>;
#define xx first
#define yy second
 
#define pb emplace_back
#define sz(x) int(x.size())
 
const int N = 2e5 + 5;
// const int INF = 1e9 + 5;
// const int mod = 1e9 + 7;
 
int a[N], dp[N];
 
void solve() {
  int n, q, l, r;
  cin >> n >> q;
 
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
 
  dp[0] = 0;
 
  int tail = INT_MIN;
  bool dec = false;
 
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
 
    if (a[i] > tail || !dec)
      dp[i]++;
 
    dec = a[i] <= tail;
    tail = a[i];
  }
 
  while (q--) {
    cin >> l >> r;
    cout << dp[r] - dp[l - 1] << endl;
  }
}
 
int main() {
  solve();
}