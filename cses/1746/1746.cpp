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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<long long> > dp(n, vector<long long>(m + 2, 0));
	if (v[0] == 0) {
		for (int i = 1; i <= m; i++) {
			dp[0][i] = 1;
		}
	} else {
		dp[0][v[0]] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (v[i] == 0) {
			for (int j = 1; j <= m; j++) {
				for (int k = -1; k < 2; k++) {
					dp[i][j] += dp[i - 1][j + k];
					dp[i][j] %= MOD;
				}
			}
		} else {
			for (int j = -1; j < 2; j++) {
				dp[i][v[i]] += dp[i - 1][v[i] + j];
				dp[i][v[i]] %= MOD;
			}
		}
	}
	long long res = 0;
	for (int i = 1; i <= m; i++) {
		res += dp[n - 1][i];
		res %= MOD;
	}
	cout << res << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
