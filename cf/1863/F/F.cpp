#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n;
    cin >> n;
    vector<long long> v(n);
    vector<vector<bool> > dp(n, vector<bool>(n, 0));
    dp[0][n - 1] = 1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
      p[i + 1] = p[i] ^ v[i];
    }
    vector<long long> a(n, 0);
    vector<long long> b(n, 0);
    vector<bool> za(n, 0);
    vector<bool> zb(n, 0);
    int k = 64 - __builtin_clzll(p[n]) - 1;
    a[0] = 1LL << k;
    b[n - 1] = 1LL << k;
    za[0] = p[n] == 0;
    zb[n - 1] = za[0];
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < n - i; j++) {
        long long x = p[i + j + 1] ^ p[j];
        dp[j][j + i] = (x & a[j]) != 0;
        dp[j][j + i] = dp[j][j + i] || (x & b[j + i]) != 0;
        if (za[j] || zb[j + i]) {
          dp[j][j + i] = 1;
        }
        if (x == 0) {
          if (dp[j][j + i]) {
            za[j] = 1;
            zb[j + i] = 1;
          }
          continue;
        }
        int k = 64 - __builtin_clzll(x) - 1;
        if (dp[j][j + i]) {
          a[j] |= (1LL << k);
          b[j + i] |= (1LL << k);
        }
      }
    }
    string res = "";
    for (int i = 0; i < n; i++) {
      if (dp[i][i]) res += '1';
      else res += '0';
    }
    cout << res << endl;
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
