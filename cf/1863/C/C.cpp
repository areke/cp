#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mis = n;
    for (int i = 0; i < n; i++) {
      mis ^= a[i];
      mis ^= i;
    }
    vector<int> c(n + 1);
    for (int i = 0; i < n; i++) {
      c[i] = a[i];
    }
    c[n] = mis;
    vector<int> res(n + 1);
    for (int i = 0; i < n; i++) { 
      int x = k % (n + 1);
      int ind = (i - x + n + 1) % (n + 1);
      res[i] = c[ind];
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
