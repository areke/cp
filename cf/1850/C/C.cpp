#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n = 8, m =8;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		string res = "";
		for (int i = 0; i < n; i++) {
			string s = "";
			for (int j = 0; j < n; j++) {
				if (v[j][i] != '.') s += v[j][i];
			}
			if (!s.empty()) res = s;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
