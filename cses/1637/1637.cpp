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
	int tests;
	int n;
	cin >> n;
	vector<long long> dp(n + 1, 1e18);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x = i;
		set<int> s;
		while (x) {
			s.insert(x % 10);
			x /= 10;
		}
		for (int y : s) {
			if (y > i) continue;
			dp[i] = min(dp[i], dp[i - y] + 1);
		}
	}
	cout << dp[n] << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
