#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, a, b;
	cin >> n >> a >> b;
	vector<long double> dp(6 * n + 1, 0);
	dp[0] = 1;
	long long x = n;
	while (x--) {
		vector<long double> ndp(6 * n + 1, 0);
		long double s = 0;
		for (int i = 0; i <= 6 * n; i++) {
			if (i > 6) {
				s-= dp[i - 7];
			}
			ndp[i] += s / 6;
			s += dp[i];
		}
		dp = ndp;
	}
	long double res = 0;
	for (int i = a; i <= b; i++) {
		res += dp[i];
	}
	cout << fixed << setprecision(6) << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
