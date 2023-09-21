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
    vector<int> p(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      m[p[i]] = i;
    }
    int res = 0;
    for (int i = 2; i <= n; i++) {
      if (m[i] < m[i - 1]) res++;
    }
    cout << res << endl;
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
