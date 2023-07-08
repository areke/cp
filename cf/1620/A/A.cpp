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
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'N') cnt++;
		}
		if (cnt == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
