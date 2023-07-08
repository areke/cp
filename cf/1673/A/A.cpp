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
		if (s.length() % 2) {
			int tot = 0;
			for (int i = 0; i < s.length(); i++) {
				tot += s[i] - 'a' + 1;
			}
			int a = tot - (s[0] - 'a' + 1);
			int b = tot - (s[s.length() - 1] - 'a' + 1);
			int c = max(a, b);
			int d = tot - c;
			if (c > d) {
				cout << "Alice " << c - d << endl;
			} else {
				cout << "Bob " << d - c << endl;
			}

		} else {
			int res = 0;
			for (int i = 0; i < s.length(); i++) {
				res += s[i] - 'a' + 1;
			}
			cout << "Alice " << res << endl;

		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
