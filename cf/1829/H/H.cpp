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

const long long MOD = 1e9+ 7;

int popcnt(int x) {
	int cnt = 0;
	for (int j = 0; j < 6; j++ ) {
		if ((1 << j) & x) cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<long long> dp(64, 0);
		dp[63] = 1;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 64; j++) {
				dp[v[i] & j] += dp[j];
				dp[v[i] & j] %= MOD;
			}
		}
		long long res = 0;
		for (int i = 0; i < 64; i++) {
			int cnt = 0;
			for (int j = 0; j < 6; j++ ) {
				if ((1 << j) & i) cnt++;
			}
			if (cnt == k) res += dp[i];
			res %= MOD;
		}
		if (k == 6) res--;
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
