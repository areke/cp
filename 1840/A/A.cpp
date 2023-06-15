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
		string s;
		cin >> s;
		string res = "";
		bool found = false;
		char cur;
		for (int i = 0; i < s.length(); i++) {
			if (!found) {
				res += s[i];
				found = true;
				cur = s[i];
			} else {
				if (cur == s[i]) {
					found = false;
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
