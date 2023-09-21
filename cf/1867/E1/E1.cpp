#include <bits/stdc++.h>
using namespace std;

int query(int ind) {
  cout << "? " << ind + 1 << endl;
  int x;
  cin >> x;
  return x;
}

int main() {
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n, k;
    cin >> n >> k;
    int v = 0;
    int a = query(0);
    query(0);
    int mod = n % k;
    int b = query(mod / 2);

//4 2
//4 2 5 1
    int res = a ^ b;
    for (int i = mod; i < n - k + 1; i+= k) {
      res ^= query(i);
    }
    cout << "! " << res << endl;
    
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
