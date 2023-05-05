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
	int tests;
	
	long long n, x;
	cin >> n >> x;

	long long dp[1000001] = {0};
	long long v[100];
	dp[0] = 1;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int ii = 0; ii < n; ii++) {
		int j = v[ii];
		for (int i = 0; i <= x; i++) {
			if (i < j) continue;
			dp[i] += dp[i - j];
			if (dp[i] >= MOD) dp[i] %= MOD;
		}
	}
	cout << dp[x] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
