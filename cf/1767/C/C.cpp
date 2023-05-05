#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<int> > g(n, vector<int>(n, 2));
		vector<vector<long long> > dp(n, vector<long long>(2, 0));

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				cin >> g[i][j];
			}
		}
		long long MOD = 998244353 ;
		dp[0][0] = 1;
		dp[0][1] = 1;

		for (int i = 1; i < n; i++) {
			if (g[i - 1][i] == 1) {
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
			} else if (g[i - 1][i] == 2) {
				dp[i][0] = dp[i - 1][1];
				dp[i][1] = dp[i - 1][0];
			} else {
				dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
				dp[i][1] = dp[i][0];
			}
			dp[i][0] %= MOD;
			dp[i][1] %= MOD;
		}
		long long res = dp[n - 1][0] + dp[n - 1][1];
		res %= MOD;
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (g[i][i] == 2) can = false;
			int maxi = 0;
			for (int j = i; j < n; j++) {
				if (maxi == 2 && g[i][j] == 1) can = false;
				maxi = max(g[i][j], maxi);
			}
		}
		if (can) {
			cout << res << endl;
		} else {
			cout << 0 << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
