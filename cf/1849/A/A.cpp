#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long b, c, h;
		cin >> b >> c >> h;
		int res = 0;
		for (int i = 2; i <= b; i++) {
			if (c + h >= i - 1) {
				res = 2 * (i - 1) + 1;
			}
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
