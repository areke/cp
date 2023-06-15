#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

// sqrt(3 * MAXN)
const int M = 100 + 1;

int m;

int dp[MAXN][2][M];

long long INF = 1e6;

long long score(long long sz, int t) {
	long long val = sz * (sz - 1) / 2 + sz;
	if (t == 1) val *= 2;
	return val;
}

void solve(int x, vector<vector<int> > & v, int last) {
	for (int n : v[x]) {
			if (n == last) continue;
			solve(n, v, x);
	}
	for (int c = 0; c < 2; c++) {
		dp[x][c][1] = 0;
		for (int n : v[x]) {
			if (n == last) continue;
			vector<int> ndp(m);
			for (int i = 0; i < m; i++) {
				ndp[i] = dp[x][c][i];
				dp[x][c][i] = INF;
			}
			long long best = INF;
			for (int j = 1; j < m; j++) {
				long long val = dp[n][c ^ 1][j];
				val += score(j, c ^ 1);
				best = min(best, val);
			}
			for (int i = 1; i < m; i++) {
				dp[x][c][i] = min(dp[x][c][i], (int)best + ndp[i]);
			}
			for (int i = 1; i < m; i++) {
				for (int j = 1; j < m; j++) {
					if (i + j >= m) break;
					dp[x][c][i + j] = min(dp[x][c][i + j], ndp[i] + dp[n][c][j]);
				}
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		m = sqrt(3 * n) + 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < m; k++) {
					dp[i][j][k] = INF;
				}
			}
		}

		vector<vector<int> > v(n);

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
			
		}
		solve(0, v, -1);
		long long res = INF;
		for (int c = 0; c < 2; c++) {
			for (int i = 1; i < m; i++) {
				long long val = dp[0][c][i];
				val += score(i, c);
				res = min(res, val);
			}
		}
		
		long long comp = 2 * (n * (n - 1) / 2  + n);
		cout << comp - res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
