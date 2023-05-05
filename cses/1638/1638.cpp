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
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<long long> > dp(n, vector<long long>(n, 0));
	if (v[0][0] != '*') dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (v[i][j] == '*') continue;
			if (i > 0) dp[i][j] += dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
			if (dp[i][j] >= MOD) dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][n - 1] << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
