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
    vector<int> a(n);
    for (int i= 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> l(n + 1, 0);
    vector<int> r(n + 1, 0);
    for (int i = 1; i < n; i++) {
      l[i] = l[i - 1];
      if (a[i] >=a[i - 1]) {
        l[i] = l[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      r[i] = r[i + 1];
      if (a[i] >= a[i + 1]) {
        r[i] = r[i + 1] + 1;
      }
    }
    int res = min(l[n - 1] + 1, r[0]);
    for (int i = 0; i < n - 1; i++) {
      res = min(res, l[i] + 1 + r[i + 1]);
    }
    cout << res << endl;
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
