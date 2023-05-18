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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, x;
	cin >> n >> x;
	vector<long long> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	const long long BAD = 1e18;
	vector<pair<int, int> > dp(1 << n, {1e9, 1e9});
	dp[0] = {1, 0};
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				if (dp[i ^ (1 << j)].second + w[j] <= x) {
					dp[i] = min(dp[i], {dp[i ^ (1 << j)].first, dp[i ^ (1 << j)].second + w[j]});
				}
				dp[i] = min(dp[i], {dp[i  ^ (1 << j)].first + 1, w[j]});
			}
		}
	}
	cout << dp[(1 << n) - 1].first << endl;
	
	


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
