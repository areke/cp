#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<vector<long long> > dp(n + 5, vector<long long>(5, -1e18));
		vector<vector<long long> > ndp = dp;
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k < 5; k++) ndp[j][k] = -1e18;
				ndp[j][0] = max(ndp[j][0], dp[j][0]);

				if (j >= 1) {
					for (int k = 1; k <= 4; k++) {
						ndp[j][k] = max(ndp[j][k], dp[j - 1][k]);
					}
				}
				if (j >= 1) {
					for (int k = 1; k <= 4; k++) {
						bool c1 = k & 1;
						bool c2 = k & 2;
						long long add = 0;
						if (c1) add += a[i - 1];
						else add -= a[i - 1];
						if (c2) add -= b[i - 1];
						else add += b[i - 1];
						ndp[j][k] = max(ndp[j][k], dp[j - 1][0] + add);	
					}
				}

				if (j >= 1) {
					for (int k = 1; k <= 4; k++) {
						bool c1 = k & 1;
						bool c2 = k & 2;
						long long add = 0;
						if (c1) add -= a[i - 1];
						else add += a[i - 1];
						if (c2) add += b[i - 1];
						else add -= b[i - 1];
						ndp[j][0] = max(ndp[j][0], dp[j - 1][k] + add);
					}
				}
				if (j >= 1) ndp[j][0] = max(ndp[j][0], dp[j - 1][0] + 2 * abs(a[i - 1] - b[i - 1]));
			}
			dp = ndp;
		}
		cout << dp[k][0] << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
