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
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s[n - i - 1]) cnt++;
    }
    cnt /= 2;
    string res(n + 1, '0');
    int t = 0;
    for (int i = cnt; i <= n - cnt; i++) {
      res[i] = '1';
      if (n % 2 == 0 && t % 2 != 0) {
        res[i] = '0';
      }
      t++;
    }
    cout << res << endl;
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
