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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<bool> > d(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++) {
			vector<int> m(n + 1, 0);
			int l = 0;
			for (int j = i; j < n; j++) {
				m[a[j]]++;
				if (m[a[j]] > m[l]) {
					l = a[j];
				}
				if (m[l] <= (j - i + 1) / 2 && (j - i + 1) % 2 == 0) {
					d[i][j] = true;
				}
			}
		}
		vector<int> dp(n + 1, -1e5);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (d[j][i - 1] && (j == 0 || a[j - 1] == a[i])) {
					dp[i + 1] = max(dp[i + 1], dp[j] + 1);
				}
			}
			if (a[i] == a[i - 1]) {
				dp[i + 1] = max(dp[i + 1], dp[i] + 1);
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i == n - 1 || d[i + 1][n - 1]) {
				res = max(res, dp[i + 1]);
			}
		}
		cout << res << endl;
		//cout << dp[n + 1] << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
