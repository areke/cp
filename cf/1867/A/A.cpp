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
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = {x, i};
    }
    sort(v.begin(), v.end());
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      res[v[i].second] = n - i;
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << " \n"[i == n - 1];
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
