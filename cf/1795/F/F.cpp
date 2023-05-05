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

const int BAD = -1e7;

int dfs(int x, vector<vector<int> > & v, vector<int> & b, vector<int> & c, vector<int> & dp, int last) {
	vector<int> children;
	int best = 0;
	int cnt = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] == last) continue;
		children.push_back(dfs(v[x][i], v, b, c, dp, x));
		if (b[x] && children.back() < 0) return dp[x] = BAD;
		else if (children.back() < 0) {
			cnt++;
			best = children.back();
		}
		if (cnt == 0)	best = max(best, children.back());
	}
	if (cnt > 1) return dp[x] = BAD;
	else if (cnt == 1) {
		for (int i = 0; i < children.size(); i++) {
			if (1 + children[i] >= abs(best)) return dp[x] = 0;
		}
	}
	if (b[x]) {
		if (best - c[x] >= 0) {
			return dp[x] = 0;
		}
		return dp[x] = -c[x];
	}
	return dp[x] = 1 + best;
}


bool solve(vector<vector<int> > & v, vector<int> & b, vector<int> & c) {
	int first = 0;
	for (int i = 0; i < b.size(); i++) {
		if (b[i]) {
			first = i;
			break;
		}
	}
	vector<int> dp(b.size(), BAD);
	dfs(first, v, b, c, dp, -1);
	for (int x : dp) {
		if (x == BAD) return false;
	}
	return dp[first] >= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		for (int i = 0; i < n -1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int k;
		cin >> k;
		vector<int> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			a[i]--;
		}
		int low = 0;
		int high = n;
		int best = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			vector<int> c(n, 0);
			vector<int> b(n, 0);
			for (int i = 0; i < k; i++) {
				c[a[i]] = mid / k + (i < (mid % k));
				b[a[i]] = 1;
			}
			bool can = solve(v, b, c);
			if (can) {
				low = mid + 1;
				best = mid;
			} else {
				high = mid - 1;
			}
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
