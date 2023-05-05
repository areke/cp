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


/**
Show that in a list a_1, a_2, ..., a_n of n integers, there exists some consecutive block sum a_i + a_{i+1} + ... + a_k that is divisible by n



a_1...a_n have no 0 % n otherwise done

**/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> dp(32769, 1e9);
		dp[32768] = 0;
		dp[0] = 0;
		for (int j = 0; j < 16; j++) {
			for (int i = 32767; i >= 1; i--) {
				dp[i] = min(dp[(2 * i) % 32768] + 1, dp[i]);
				dp[i] = min(dp[i + 1] + 1, dp[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << dp[a[i]] << " ";
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
