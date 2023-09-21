#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		if (n < m) {
			swap(n, m);
		}
		int dx = n - m;
		int res = n + m - 2;
		if (m == 1 && n > 2) {
			cout << -1 << endl;
			continue;
		}
		dx--;
		if (dx > 0) {
			res += dx;
			if (dx & 1) res++;
		}
		cout << res << endl;


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
