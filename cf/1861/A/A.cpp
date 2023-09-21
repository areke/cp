#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    string s;
    cin >> s;
    bool one = false;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1' || s[i] == '3') {
        if (s[i] == '1') {
          one = true;
          break;
        } else {
          break;
        }
      }
    }
    if (one) {
      cout << 13 << endl;
    } else {
      cout << 31 << endl;
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
