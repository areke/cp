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
long long INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<long long> dp(4, INF);
		dp[0]= 0;
		int n;
		cin >> n;

		for (int i = 0;i < n; i++) {
			long long x;
			string s;
			cin >> x;
			cin >> s;
			int res = 0;
			for (int i = 0; i < 2; i++) {
				res *= 2;
				res += (s[i] - '0');
			}
			dp[res] = min(dp[res], x);
		}
		dp[3] = min(dp[3], dp[1] + dp[2]);
		if (dp[3] == INF) cout << -1 << endl;
		else cout << dp[3] << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
