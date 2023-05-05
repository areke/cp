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


vector<long long> dp(1e6 + 5, -1);
long long MOD = 1e9 + 7;
long long	solve(long long x) {
	
	if (x < 0) return 0;
	if (dp[x] != -1) return dp[x];
	if (x == 0) return 1;
	long long res = 0;
	for (int i = 1; i <= 6; i++) {
		res += solve(x - i);
		res %= MOD;
	}
	return dp[x] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << solve(n) << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
