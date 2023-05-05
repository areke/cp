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
		string s;
		cin >> s;
		vector<long long> dp(n);
		dp[0] = 1;
		long long MOD = 998244353;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				dp[i] = dp[i - 1] * 2;
			} else {
				dp[i] = 1;
			}
			dp[i] %= MOD;
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += dp[i];
			res %= MOD;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
