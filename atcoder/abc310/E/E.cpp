#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(n);
	for (int i = 0; i < s.length(); i++) {
		v[i] = s[i] - '0';
	}
	vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
	dp[0][v[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j && v[i]) {
				dp[i][0] += dp[i - 1][j];
			} else {
				dp[i][1] += dp[i - 1][j];
			}
		}
		dp[i][v[i]]++;
	}
	//
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += dp[i][1];
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
