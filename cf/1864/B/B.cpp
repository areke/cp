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
    string s;
    cin >> s;
    if (k % 2 == 0) {
      sort(s.begin(), s.end());
      cout << s << endl;
      continue;
    }
    vector<string> v(2);
    for (int i = 0; i < n; i++) {
      v[i & 1] += s[i];
    }
    for (int i = 0; i < 2; i++) {
      sort(v[i].begin(), v[i].end());
    }
    string t = "";
    string u = "";
    for (int i = 0; i < n; i++) {
      t += v[i & 1][i / 2];
    }
    cout << t << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
