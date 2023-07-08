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
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		vector<int> res(n + 1, 1e6);
		vector<vector<int> > dp(n + 1, vector<int>(n + 5, -1e6));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k <= n; k++) {
					if (j == 0 || c[j - 1] < c[i - 1]) {
						if (j == i - 1) {
							dp[i][k] = max(dp[i][k], dp[j][k] + 1);
						} else {
							dp[i][k + 1] = max(dp[i][k + 1], dp[j][k] + 1);
						}
					}
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j == n) {
					res[i] = min(res[i], n - dp[j][i]);
				} else if (i > 0) {
					res[i] = min(res[i], n - dp[j][i - 1]);
				}
			}
			if (i > 0) res[i] = min(res[i], res[i - 1]);
		}
		for (int i = 1; i <= n; i++) {
			cout << res[i] << " \n"[i == n];
		}


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
