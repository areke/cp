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
		if (n == 1 || m == 1 || (__gcd(n* m, 2 * n - 1) != 1 && __gcd(n* m, 2 * m - 1))) {
			cout << -1 << endl;
			continue;
		}
		vector<vector<int> > res(n, vector<int>(m, 0));
		if (gcd(n* m, (2 * n - 1)) != 1) {
			int cnt = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (i & 1) {
						res[i][m - j - 1] = cnt++;
					} else {
						res[i][j] = cnt++;
					}
				}
			}
		} else {
			int cnt = 1;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (i & 1) {
						res[n - j - 1][i] = cnt++;
					} else {
						res[j][i] = cnt++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j] << " \n"[j == m - 1];
			}
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
