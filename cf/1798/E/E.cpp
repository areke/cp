#include <bits/stdc++.h>
using namespace std;

int solve(int x, vector<int> & v, vector<int> & dp) {
	if (dp[x] != -1) return dp[x];
	if (v[x] + x + 1 == v.size()) {
		return dp[x] = 1;
	} else if (v[x] + x + 1 > v.size()) {
		return dp[x] = 0;
	}
	int can = solve(x + v[x] + 1, v, dp);
	if (can) dp[x] = can + 1;
	else dp[x] = 0;
	return dp[x];
}

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
		vector<int> dp(n, -1);
		for (int i = 0; i < n; i++) {
			solve(i, v, dp);
		}
		vector<int> res(n - 1, 0);
		vector<int> best(n, 0);
		int maxi = dp[n - 1];
		best[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			best[i] = maxi + 1;
			if (v[i] + i < n) {
				best[i] = max(best[i], best[v[i] + i] + 1);
			}
			maxi = max(maxi, dp[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			res[i] = 2;
			if (v[i] == dp[i + 1]) {
				res[i] = 0;
			} else if (dp[i + 1] || best[i + 1] >= v[i]) {
				res[i] = 1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			cout << res[i] << " \n"[i == n - 2];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
