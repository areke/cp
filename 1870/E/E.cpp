#include <bits/stdc++.h>
using namespace std;
 
short mx[5005][5005];
bool dp[5005][10005];
 
short mp[10005][5005];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < 2 * n + 1; j++) {
        dp[i][j] = 0;
        mp[j][i] = -1;
      }
    }
 
    for (int i = 0; i < n; i++) {
      vector<int> s(n + 2, 0);
      int cur = 0;
      for (int j = i; j < n; j++) {
        s[a[j]] = 1;
        while (s[cur]) {
          cur++;
        }
        mx[i][j] = cur;
        mp[cur][j] = i;
      }
    }
    vector<int> p(2 * n + 1, 0);
    vector<bool> c(2 * n + 1, 0);
    dp[0][0] = 1;
 
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 2 * n + 1; k++) {
        if (dp[i][k] && !c[k]) {
          for (int j = 0; j <= n; j++) {
            while (p[j] < n && mp[j][p[j]] < i) {
              p[j]++;
            }
            if (p[j] >= n) continue;
            dp[p[j] + 1][k ^ j] = 1;
            res = max(res, k ^ j);
          }
        }
        c[k] = c[k] || dp[i][k];
      }
    }
    cout << res << "\n";
  }
 
  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}