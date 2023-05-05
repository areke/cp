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

	vector<long long> dp(x + 1, 0);
	vector<long long> v;
	v.resize(n);
	dp[0] = 1;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int j : v) {
		for (int i = 1; i <= x; i++) {
		
			if (j > i) continue;
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
