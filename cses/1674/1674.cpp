#include <bits/stdc++.h>
using namespace std;

int dfs(int x, vector<vector<int> > & v, vector<int> & dp) {
	int res = 1;
	for (int n : v[x]) {
		res += dfs(n, v, dp);
	}
	return dp[x] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		v[x].push_back(i);
	}
	vector<int> dp(n, 0);
	dfs(0, v, dp);
	for (int i = 0; i < n; i++) {
		cout << dp[i] - 1 << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
