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

void dfs(int x, int dist, vector<vector<int> > & v, int last, vector<long long> & d) {
	d[x] = dist;
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, dist + 1, v, x, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k, c;
		cin >> n >> k >> c;
		vector<long long> d(n);
		vector<vector<int> > v(n);
		for (int i = 0; i < n - 1;i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(0, 0, v, -1, d);
		int ind = 0;
		for (int i = 0; i < n; i++) {
			if (d[i] > d[ind]) {
				ind = i;
			}
		}
		vector<long long> d2(n);
		dfs(ind, 0, v, -1, d2);
		int ind2 = 0;
		for (int i = 0; i < n; i++) {
			if (d2[i] > d2[ind2]) {
				ind2 = i;
			}
		}
		vector<long long> d3(n);
		dfs(ind2, 0, v, -1, d3);
		long long res = -2e18;
		for (int i = 0; i < n; i++) {
			long long sc = max(k * d2[i], k * d3[i]) - c * d[i];
			res = max(res, sc);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
