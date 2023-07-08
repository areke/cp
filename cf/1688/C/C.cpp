#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		
		set<char> c;
		map<char, int> m;
		for (int i = 0; i < 2 * n + 1; i++) {
			string s;
			cin >> s;
			if (s.length() == 1) {
				c.insert(s[0]);
			}
			for (char y : s) {
				m[y]++;
			}
		}
		char res = 'a';
		for (char x : c) {
			if (m[x] & 1) {
				res = x;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
