#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int cur = a;
    int cnt = a;
    int best = a;
    for (int i = 0; i < q; i++) {
      if (s[i] == '+') {
        cur++;
        cnt++;
      } else {
        cnt--;
      }
      best = max(best, cnt);
    }
    if (best == n) {
      cout << "YES" << endl;
    } else if (cur >= n) {
      cout << "MAYBE" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
