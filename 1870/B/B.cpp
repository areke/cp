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
    vector<long long> a(n);
    vector<long long> b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    long long res = 0;
    long long x = 0;
    for (int i = 0; i < m; i++) {
      x |= b[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans ^= a[i];
    }
    for (int i = 0; i < n; i++) {
      res ^= (a[i] | x);
    }
    
    if (n & 1) {
      cout << ans << " " << res << endl;
    } else {
      
      cout << res << " " << ans << endl;
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
