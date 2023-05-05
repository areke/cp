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

long long MOD = 1e9 + 7;
vector<long long> dp(1e6 + 1, -1);
vector<long long> v;

long long solve(long long x) {
	
	if (x < 0) return 1e18;
	if (dp[x] != -1) return dp[x];
	if (x == 0) return 0;
	long long res = 1e18;
	for (long long y : v) {
		res = min(res, solve(x - y) + 1);
	}
	return dp[x] = res;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	
	long long n, x;
	cin >> n >> x;
	v.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long ans = solve(x);
	if (ans == 1e18) {
		cout << -1 << endl;
	} else {
		cout << solve(x) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
