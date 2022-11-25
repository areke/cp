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
	int tests = 1;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, long long> > > v(n);

		vector<vector<pair<int, long long> > > r(n);
		for (int i = 0; i < m; i++) {
			int x, y;
			long long w;
			cin >> x >> y >> w;
			x--;
			y--;
			v[x].push_back({y, w});
			r[y].push_back({x, w});
		}
		priority_queue<array<long long, 2> > pq;
		pq.push({0, 0});
		long long bad = 1e18;
		vector<long long> costs(n, bad);

		vector<long long> rcosts(n, bad);
		while (!pq.empty()) {
			auto top = pq.top();
			pq.pop();
			if (costs[top[1]] <= abs(top[0])) {
				continue;
			}
			costs[top[1]] = -top[0];
			for (int i = 0; i < v[top[1]].size(); i++) {
				array<long long, 2> next = {top[0] - v[top[1]][i].second, v[top[1]][i].first};
				pq.push(next);
			}
		}
		for (int i = 0; i < n; i++) {
			if (costs[i] != bad) {
				pq.push({-costs[i], i});
			}
		}
		
		while (!pq.empty()) {
			auto top = pq.top();

			pq.pop();
			if (rcosts[top[1]] <= abs(top[0])) {
				continue;
			}
			rcosts[top[1]] = -top[0];
			for (int i = 0; i < r[top[1]].size(); i++) {
				array<long long, 2> next = {top[0] - r[top[1]][i].second, r[top[1]][i].first};
				pq.push(next);
			}
		}
		for (int i = 1; i < n; i++) {
			if (rcosts[i] == bad) {
				cout << -1;
			} else {
				cout << rcosts[i];
			}
			if (i == n - 1) cout << endl;
			cout << " ";
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
