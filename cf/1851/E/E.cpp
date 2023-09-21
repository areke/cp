#include <bits/stdc++.h>
using namespace std;

long long solve(int x, vector<long long> & dp, vector<bool> & vis, const vector<vector<int> > & v, const vector<long long> & c) {
	if (vis[x]) return dp[x];
	//cout << x << endl;
	vis[x] = true;
	long long res = c[x];
	if (v[x].empty()) return dp[x] = res;
	long long build = 0;
	for (int n : v[x]) {
		build += solve(n, dp, vis, v, c);
	}
	return dp[x] = min(build, res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<bool> vis(n, 0);
		vector<long long> c(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		vector<long long> dp(n, 0);
		vector<vector<int> > v(n);
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			x--;
			vis[x] = true;
		}
		for (int i = 0; i < n; i++) {
			int m;
			cin >> m;
			v[i].resize(m);
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				v[i][j]--;
			}
		}

		for (int i = 0; i < n; i++) {
			solve(i, dp, vis, v, c);
		}
		for (int i = 0; i < n; i++) {
			cout << dp[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
