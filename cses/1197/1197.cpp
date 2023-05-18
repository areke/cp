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
	vector<array<long long, 3> > e;
	map<pair<int, int>, long long> mp;
	for (int i = 0; i < m; i++) {
		int x, y;
		long long w;
		cin >> x >> y >> w;
		x--;
		y--;
		e.push_back({x, y, w});
		mp[{x, y}] = w;
	}
	vector<vector<long long> > res(n + 1, vector<long long>(n, 0));
	vector<vector<int> > last(n + 1, vector<int>(n, -1));

	for (int i = 1; i <= n; i++) {
		last[i] = last[i - 1];
		for (auto ed : e) {
			if (res[i - 1][ed[0]] + ed[2] < res[i][ed[1]]) {
				last[i][ed[1]] = ed[0];
				res[i][ed[1]] = res[i - 1][ed[0]] + ed[2];
			}
		}
	}
	vector<int> c;
	for (int i = 0; i < n; i++) {
		if (res[n][i] < res[n - 1][i]) {
			int cur = i;
			int ind = n;
			c.push_back(cur);
			while (ind--) {
				c.push_back(last[n][cur]);
				cur = last[n][cur];

			}
			reverse(c.begin(), c.end());
			break;
		}
	}
	vector<int> cycle;
	set<int> s;
	for (int x : c) {
		if (s.find(x) != s.end()) break;
		cycle.push_back(x);
		s.insert(x);
	}

	if (cycle.size()) {
		cout << "YES" << endl;
		cycle.push_back(cycle[0]);

		for (int i = 0; i < cycle.size() - 1; i++) {
			assert(mp.count({cycle[i], cycle[i + 1]}));
		}
		for (int i = 0; i < cycle.size(); i++) {
			cout << cycle[i] + 1 << " \n"[i == cycle.size() - 1];
		}
	} else {
		cout << "NO" << endl;
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
