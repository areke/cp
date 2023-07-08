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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<int> l(n + 1, -1);
		vector<vector<int> > dp(n + 1, vector<int>(2, -1e6));
		dp[0][1] = 0;
		for (int i = 0; i < n; i++) {
			dp[i + 1][0] = max(dp[i][0], dp[i][1]);
			if (l[v[i]] != -1) {
				dp[i + 1][1] = max(dp[l[v[i]] + 1][0] + i - l[v[i]] + 1, dp[l[v[i]] + 1][1] + i - l[v[i]]);
			}
			l[v[i]] = i;
		}
		cout << max(dp[n][0], dp[n][1]) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
