#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, k, x;
    cin >> n >> k >> x;
    if (k > n || x < k - 1) {
      cout << -1 << endl;
      continue;
    }
    long long res = (k - 1) * (k) / 2;
    int add = x;
    if (x == k) add--;
    res += (n - k) * add;
    cout << res << endl;
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
