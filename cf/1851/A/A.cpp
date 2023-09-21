#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, m, k, h;
		cin >> n >> m >> k >> h;
		int res = 0;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if (x % k == h % k && h != x) {
				if (abs(h - x) / k < m) {
					res++;
				}
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
