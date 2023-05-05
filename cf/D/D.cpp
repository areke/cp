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

long long MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long SHIFT = 300 * 300;
	vector<vector<long long> > dp(2, vector<long long>(SHIFT * 4 + 1, 0));
	dp[0][v[1] + SHIFT] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = -SHIFT; j <= SHIFT; j++) {
			//cout << " " << v[i + 1] + j + SHIFT << endl;
			dp[1][v[i + 1] + j + SHIFT] += dp[0][j + SHIFT];
			dp[1][v[i + 1] + j + SHIFT] %= MOD;
			if (j != 0) {
				dp[1][v[i + 1] - j + SHIFT] += dp[0][j + SHIFT];
				dp[1][v[i + 1] - j + SHIFT] %= MOD;
			}
		}
		dp[0] = dp[1];
		for (int j = -SHIFT; j <= SHIFT; j++) {
			dp[1][j + SHIFT] = 0;
		}
	}
	long long res =0;
	for (int i = 0; i < dp[0].size(); i++) {
		res += dp[0][i];
		res %= MOD;
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
