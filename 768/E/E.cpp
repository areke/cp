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


int solve(int x, long long used, map<pair<int, long long>, int> & m) {
	if (m.count({x, used})) return m[{x, used}];
	int res = 0;
	long long bad = (1LL << x) - 1;
	int mex = 0;
	long long s = 0;
	for (int i = 1; i <= x; i++) {
		if (used & (1LL << i)) continue;
		long long nused = (used | (1LL << i)) & bad;
		int next = x - i;
		s |= (1LL << solve(next, nused, m));
	}
	for (int i = 0; i <= 60; i++) {
		if ((1LL << i) & s) mex++;
	}
	return m[{x, used}] = mex;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<pair<int, long long>, int> dp;
	dp[{0, 0}] = 0;
	vector<int> g(61, 0);
	for (int i = 0; i <= 60; i++) {
		g[i] = solve(i, 0, dp);
	}
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		x ^= g[y];
	}
	if (x) {
		cout << "NO" << endl; 
	} else {
		cout << "YES" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
