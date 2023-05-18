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

struct loc {
	int x, u;
	long long d;
	bool operator<(const loc & a) const {
		return this->d > a.d;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long> > > v(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		v[x].push_back({y, w});
	}
	vector<long long> d(2 * n, 1e18);
	vector<bool> vis(2 * n, 0);
	priority_queue<loc> pq;
	pq.push({0, 0, 0});
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		if (vis[t.x + n * t.u]) continue;
		vis[t.x + n * t.u] = true;
		d[t.x + n * t.u] = t.d;
		for (auto n : v[t.x]) {
			pq.push({n.first, t.u, t.d + n.second});
			if (!t.u) {

				pq.push({n.first, 1, t.d + n.second / 2});
			}
		}
	}
	cout << d[n + n - 1] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
