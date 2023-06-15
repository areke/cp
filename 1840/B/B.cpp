#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long c = 1;
		long long n, k;
		cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			c *= 2;
			if (c > n) break;
		}
		if (c > n) {
			cout << n + 1 << endl;
		} else {
			cout << c << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
