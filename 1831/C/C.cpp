#include <bits/stdc++.h>
using namespace std;


void solve(int x, vector<vector<int> > & v, vector<int> & dp, map<pair<int, int>, int> & m, int last, int ind) {
	int nind;
	if (last != -1) {
		nind = m[{last, x}];
		if (nind > ind) {
			dp[x] = dp[last];
		} else {
			dp[x] = dp[last] + 1;
		}
	} else {
		nind = 1e6;
	}
	for (int n : v[x]) {
		if (n == last) continue;
		solve(n, v, dp, m, x, nind);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		map<pair<int, int>, int> m;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
			m[{x, y}] = i;
			m[{y, x}] = i;
		}
		vector<int> dp(n, 0);
		dp[0] = 0;
		solve(0, v, dp, m, -1, -1);
		long long maxi = 0;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, (long long)dp[i]);
		}
		cout << maxi << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
