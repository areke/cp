#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<vector<int> > u(n);
    vector<vector<int> > l(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 'U') {
          u[i].push_back(j);
        } else if (v[i][j] == 'L') {
          l[j].push_back(i);
        }
      }
    }
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (((int)u[i].size()) & 1) can = false; 
    }
    for (int i = 0; i < m; i++) {
      if (((int) l[i].size()) & 1) can = false;
    }
    if (!can) {
      cout << -1 << endl;
      continue;
    }
    vector<string> res(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < u[i].size(); j++) {
        if (j & 1) {
          res[i][u[i][j]] = 'W';
          res[i + 1][u[i][j]] = 'B';
        } else {
          res[i][u[i][j]] = 'B';
          res[i + 1][u[i][j]] = 'W';
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < l[i].size(); j++) {
        if (j & 1) {
          res[l[i][j]][i] = 'W';
          res[l[i][j]][i + 1] = 'B';
        } else {
          res[l[i][j]][i] = 'B';
          res[l[i][j]][i + 1] = 'W';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << endl;
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
