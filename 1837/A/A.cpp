#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int x, k;
		cin >> x >> k;
		if (x % k != 0) {
			cout << 1 << endl;
			cout << x << endl;
		} else {
			cout << 2 << endl;
			cout << x + 1 << " " << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
