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
long long dp[1048576][20];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n);

	vector<vector<int> > r(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		r[y].push_back(x);
	}
	dp[1][0] = 1;
	for (int i = 2; i < (1 << n) - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if ((1 << j) & i) {
				int unset = i ^ (1 << j);
				for (int & k : r[j]) {
					dp[i][j] += dp[unset][k];
					if (dp[i][j] >= MOD) dp[i][j] %= MOD;
				}
			}
		}
	}
	int LAST  = (1 << n) - 1;
	for (int j = 0; j < n; j++) {
		if ((1 << j) & LAST) {
			int unset = LAST ^ (1 << j);
			for (int & k : r[j]) {
				dp[LAST][j] += dp[unset][k];
				if (dp[LAST][j] >= MOD) dp[LAST][j] %= MOD;
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1] << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
