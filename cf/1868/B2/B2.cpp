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
    long long su = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      su += v[i];
    }
    if (su % n != 0) {
      cout << "No" << "\n";
      continue;
    }
    long long tar = su / n;
    vector<long long> a(40, 0), b(40, 0), c(40, 0);

    string ans = "Yes";
    for (int i = 0; i < n; i++) {
      bool found = false;
      for (int j = 0; j < 33; j++) {
        long long x = 1LL << j;
        for (int k = 0; k < 33; k++) {
          long long y = 1LL << k;
          if (x - y == tar - v[i]) {
            found = true;
            a[j]++;
            a[k]--;
          }
        }
      }
      if (!found) ans = "No";
      for (int j = 0; j < 33; j++) {
        if ((1LL << j) == tar - v[i]) b[j]++;
        else if ((1LL << j) == v[i] - tar) c[j]++;
      }
    }
    for (int i = 0; i < 39; i++) {
      int need = a[i];
      if (need % 2 != 0) {
        ans = "No";
        break;
      }
      need /= 2;
      if (need > 0) {  
        if (need > c[i]) ans = "No";
        a[i + 1] += need;
      } else if (need < 0) {
        if (abs(need) > b[i]) ans = "No";
        a[i + 1] += need;
      }
    }
    cout << ans << "\n";
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
