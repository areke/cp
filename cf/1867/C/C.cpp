#include <bits/stdc++.h>
using namespace std;

int query(int x) {
  cout << x << endl;
  int y;
  cin >> y;
  return y;
}

int main() {
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; test++) {
    int n;
    cin >> n;
    set<int> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
      s.insert(v[i]);
    }
    int mx = 0;
    for (int i = 0; i <= n; i++) {
      if (!s.count(i)) {
        mx = i;
        break;
      }
    }
    bool done = true;
    while (mx >= 0) {
      mx = query(mx);
    }
  }


  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
