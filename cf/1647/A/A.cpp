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
		string res = "";
		int s = 0;
		int last = 0;
		while (s < n) {
			if (last != 1) {
				s++;
				last = 1;
				res +='1';
			} else {
				last = 2;
				s += 2;
				res += '2';
			}
		}
		if (s > n) res = "";
		string cur = "2";
		s = 2;
		last = 2;
		while (s < n) {
			if (last != 1) {
				s++;
				last = 1;
				cur +='1';
			} else {
				last = 2;
				s += 2;
				cur += '2';
			}
		}
		if (s > n) cur = "";
		if (cur.length() >= res.length()) {
			res = cur;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
