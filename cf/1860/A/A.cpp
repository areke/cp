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
		if (s == "()") {
			cout << "NO" << endl;
			continue;
		}
		int n = s.length();
		string t = "";
		for (int i = 0; i < n; i++) {
			t += '(';
		}
		for (int i = 0; i < n; i++) {
			t += ')';
		}
		string u = "";
		for (int i = 0; i < n; i++) {
			u += "()";
		}
		cout << "YES" << endl;
		if (t.find(s) == string::npos) {
			cout << t << endl;
		} else {
			assert(u.find(s) == string::npos);
			
			cout << u << endl;
			
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
