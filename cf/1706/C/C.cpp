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
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		vector<pair<int, long long> > dp(n + 1);
		dp[0]= {0, 0};
		for (int i = 1; i < n - 1; i++) {
			dp[i + 1] = max(dp[i + 1], dp[i]);
			long long c = max(0LL, max(h[i - 1], h[i + 1]) + 1 - h[i]);
			dp[i + 1] = max(dp[i + 1], {dp[i - 2 + 1].first + 1, dp[i - 2 + 1].second - c});
			if (i > 2) {
				dp[i + 1] = max(dp[i + 1], {dp[i - 3 + 1].first + 1, dp[i - 2 + 1].second - c});
			}
		}
		cout << -dp[n - 1].second << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
