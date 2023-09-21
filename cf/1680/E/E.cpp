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
		string v[2];
		for (int i = 0; i < 2; i++) {
			cin >> v[i];
		}
		int f = -1;
		int l = -1;
		
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				if (v[i][j] == '*') {
					if (f == -1) f = j;
					l = j;
				}
			}
		}

		auto solve = [&](int first, int last) {

			vector<vector<int> > dp(2, vector<int>(n, 0));
			if (v[0][first] == '*' && v[1][first] == '*') {
				dp[0][first] = 1;
				dp[1][first] = 1;
			} else if (v[0][first] == '*') {
				dp[0][first] = 0;
				dp[1][first] = 1;
			} else {
				dp[0][first] = 1;
				dp[1][first] = 0;
			}
			
			for (int j = first + 1; j <= last; j++) {
				if (v[0][j] == '*' && v[1][j] == '*') {
					dp[0][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 2);
					dp[1][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 2);
				} else if (v[0][j] == '*') {
					dp[0][j] = min(dp[0][j - 1] + 1, dp[1][j - 1] + 2);
					dp[1][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 2);
				} else if (v[1][j] == '*') {
					dp[0][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 2);
					dp[1][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 1);
				} else {
					dp[0][j] = min(dp[0][j - 1] + 1, dp[1][j - 1] + 2);
					dp[1][j] = min(dp[0][j - 1] + 2, dp[1][j - 1] + 1);
				}
			}
			return dp;

		};
		auto left = solve(f, l);
		cout << min(left[0][l], left[1][l]) << endl;		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
