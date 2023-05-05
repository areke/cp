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

long long solve(vector<vector<long long> > & v, long long m) {
	multiset<long long> costs;
	for (int j = 0; j < m; j++) {
		costs.insert(v[0][j] + 2 * m - j - 1);
	}
	for (int j = 0; j < m; j++) {
		costs.insert(v[1][j] + j);
	}
	long long cnt = 0;
	long long res = 1e18;
	long long cur = 2 * m - 1;
	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			long long now = 0;
			if (!costs.empty()) now = *(costs.rbegin()) - i;
			res = min(res, max(cur, now));
		} 
		long long top = v[0][i] + 2 * m - i - 1;
		long long bot = v[1][i] + i;
		if (i % 2 == 0) {
			cur = max(cur, (2 *m - 2 * i - 1) + v[0][i]);
			cur = max(cur, (2 *m -(2 * i + 1) - 1) + v[1][i]);
		} else {
			cur = max(cur, (2 *m - (2 * i + 1) - 1) + v[0][i]);
			cur = max(cur, (2 *m -(2 * i) - 1) + v[1][i]);
		}
		costs.erase(costs.find(top));
		costs.erase(costs.find(bot));
	}
	return min(res, cur);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int m;
		cin >> m;
		vector<vector<long long> > v(2, vector<long long>(m));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if (v[i][j] != 0) v[i][j]++;
			}
		}
		long long res = solve(v, m);
		long long cur = max((long long)2 * m - 1, v[1][0] + 2 * m - 2);
		v[0].erase(v[0].begin());
		v[1].erase(v[1].begin());

		swap(v[0], v[1]);
		res = min(res, max(cur, solve(v, m - 1)));
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
