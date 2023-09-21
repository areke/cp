#include <bits/stdc++.h>
using namespace std;

int main() {
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long p = 1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    bool can = false;
    for (int i = 0; i < n; i++) {
      p *= v[i];
      if (p > 1e9) {
        can = true;
        break;
      }
    }
    if (can) {
      int f = -1;
      int l = n - 1;
      for (int i = 0; i < n; i++) {
        if (f == -1 && v[i] != 1) f = i;
        if (v[i] != 1) l = i;
      }
      cout << f + 1 << " " << l + 1 << endl;
    } else {
      int cnt = 0;
      vector<long long> p(n + 1, 0);
      vector<long long> s(n + 1, 0);
      p[0] = 1;
      for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] * v[i];
        s[i + 1] = s[i] + v[i];
      }
      vector<int> ind;
      for (int i = 0; i < n; i++) {
        if (v[i] != 1) {
          ind.push_back(i);
        }
      }
      long long res = -1;
      pair<int, int> ans = {0, 0};
      for (int i = 0; i < ind.size(); i++) {
        for (int j = i; j < ind.size(); j++) {
          long long cur = s[ind[i]] + (p[ind[j] + 1] / p[ind[i]]) + (s[n] - s[ind[j] + 1]);
          if (cur >= res) {
            res = cur;
            ans = {ind[i], ind[j]};
          }
        }
      }
      cout << ans.first + 1 << " " << ans.second  + 1 << endl;

    }

  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
