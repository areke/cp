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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n);

	vector<vector<int> > r(n);

	vector<int> c(n, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		r[y].push_back(x);
		c[y]++;
	}
	bool can = true;
	vector<int> res;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!c[i]) q.push(i);
	}
	while (!q.empty()) {
		int t = q.front();
		res.push_back(t);
		q.pop();
		for (int j : v[t]) {
			c[j]--;
			if (c[j] == 0) q.push(j);
		}
	}

	vector<int> dp(n, 0);
	vector<int> last(n, -1);
	const long long MOD = 1e9 + 7;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int x = res[i];
		for (int j : r[x]) {
			dp[x] += dp[j];
			dp[x] %= MOD;
			if (dp[x] == dp[j] + 1) {
				last[x] = j;
			}
		}
	}
	cout << dp[n - 1] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
