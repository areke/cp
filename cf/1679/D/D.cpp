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

long long dfs(int x, long long mid, vector<long long> & a, vector<vector<int> >  & v, vector<int> & col, vector<long long> & dp) {
	if (col[x] == 2) {
		return dp[x];
	} else if (col[x] == 1) {
		return 1e18 + 1;
	}
	col[x] = 1;
	long long res = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (a[v[x][i]] > mid) continue;
		res = max(res, dfs(v[x][i], mid, a, v, col, dp) + 1);
	}
	col[x] = 2;
	return dp[x] = res;
}

bool solve(long long mid, vector<long long> & a, vector<vector<int> > & v, long long k) {
	int n = a.size();
	long long res = 0;
	vector<int> col(n, 0);
	vector<long long> dp(n, 0);
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) continue;
		long long maxi = dfs(i, mid, a, v, col, dp);
		res = max(maxi, res);
	}
	return res >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		long long n, m, k;
		cin >> n >> m >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int> > v(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			v[a].push_back(b);
		}
		long long low = 1;
		long long high = 1e9;
		long long best = 1e10;
		while (low <= high) {
			long long mid = (low + high) / 2;
			bool b = solve(mid, a, v, k);
			if (b) {
				best = min(best, mid);
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		if (best == 1e10) {
			cout << -1 << endl;
		} else {
			cout << best << endl;
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
