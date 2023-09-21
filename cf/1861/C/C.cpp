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
    int cur = 0;
    int a = 0;
    int b = 1e9;
    bool can = true;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '+') {
        cur++;
      } else if (s[i] == '-') {
        cur--;
        if (a > cur) a--;
        if (b > cur) b = 1e9;
      } else if (s[i] == '0') {
        if (cur == a || cur == 1) {
          can = false;
        }
        b = min(b, cur);
      } else {
        if (cur >= b) {
          can = false;
        }
        a = cur;
      }
    }
    if (can) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
 
  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}