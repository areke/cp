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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<int> c(30, 0);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 30; j++) {
        if (v[i] >> j & 1) c[j]++;
      }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
      bool can = true;
      for (int j = 0; j < 30; j++) {
        if (c[j] % i != 0) {
          can = false;
        }
      }
      if (can) res.push_back(i);
    }
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " \n"[i == res.size() - 1];
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
