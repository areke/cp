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
		vector<vector<bitset<2001> > > dp(n, vector<bitset<2001> > (m, 0));
		
		vector<vector<int> > v(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		dp[0][0].flip(1001 + v[0][0]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i > 0) {
					if (v[i][j] == -1) {
						dp[i][j] |= (dp[i - 1][j] >> 1);
					} else {
						dp[i][j] |= (dp[i - 1][j] << 1);
					}
				}
				if (j > 0) {
					if (v[i][j] == -1) {
						dp[i][j] |= (dp[i][j - 1] >> 1);
					} else {
						dp[i][j] |= (dp[i][j - 1] << 1);
					}
				}
			}
		}
		if (dp[n - 1][m - 1].test(1001)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
