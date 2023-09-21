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
		string res = "YES";
		int n = s.length();
		for (int i = 0; i < s.length(); i++) {
			bool ok = false;
			if (i > 0 && s[i - 1] == s[i]) ok = true;
			if (i < n - 1 && s[i + 1] == s[i]) ok = true;
			if (!ok) res = "NO";
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
