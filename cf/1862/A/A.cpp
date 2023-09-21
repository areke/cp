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
    string s = "vika";
    string res = "NO";
    int p = 0;
    for (int j = 0; j < m; j++) {
      bool f = false;
      for (int i = 0; i < n; i++) {
        if (p < 4 && v[i][j] == s[p]) {
          p++;
          break;
        }
      }
    }
    if (p == 4) {
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
