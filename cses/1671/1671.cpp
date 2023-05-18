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
	int x;
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
	vector<long long> d(n, 0);
	vector<bool> vis(n, 0);
	priority_queue<loc> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		if (vis[t.x]) continue;
		vis[t.x] = true;
		d[t.x] = t.d;
		for (auto n : v[t.x]) {
			pq.push({n.first, t.d + n.second});
		}
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
