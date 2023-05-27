#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
	if (n == 1) return 1;
	if (2 * k <= n) {
		return 2 * k;
	}
	if (n % 2 == 0) {
		long long x = solve(n / 2, k - n / 2);
		return 2 * x - 1;
	} else {
		long long x = 2 * solve(n / 2 + 1, k - n / 2) - 1;
		if (x - 2 >= 1) return x - 2;
		return n;
		// n / 2 + 1
	}
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
