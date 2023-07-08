#include <bits/stdc++.h>
using namespace std;

bool check(char c, vector<string> & s) {
	for (int i = 0; i < 3; i++) {
		bool can = true;
		for (int j = 0; j < 3; j++) {
			if (s[i][j] != c) can = false;
		}
		if (can) return true;
	}
	
	for (int i = 0; i < 3; i++) {
		bool can = true;
		for (int j = 0; j < 3; j++) {
			if (s[j][i] != c) can = false;
		}
		if (can) return true;
	}

	bool can = true;
	for (int i = 0; i < 3; i++) {
		if (s[i][i] != c) can = false;
	}
	if (can) return true;

	can = true;
	for (int i = 0; i < 3; i++) {
		if (s[2 - i][i] != c) can = false;
	}

	if (can) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<string> s(3);
		for (int i = 0; i < 3; i++) {
			cin >> s[i];
		}
		char res = '-';
		vector<char> pos = {'+', 'O', 'X'};
		for (int i = 0; i < 3; i++) {
			if (check(pos[i], s)) {
				res = pos[i];
			}
		}
		if (res == '-') {
			cout << "DRAW" << endl;
		} else {
			cout << res << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
