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
	int x, l;
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
	vector<vector<pair<int, long long> > > r(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		v[x].push_back({y, w});
		r[y].push_back({x, w});
	}
	vector<long long> d(n, 0);
	vector<long long> c(n, 0);
	vector<long long> mini(n, 1e18);
	vector<long long> maxi(n, -1e18);
	c[0] = 1;
	mini[0] = 0;
	maxi[0] = 0;
	vector<bool> vis(n, 0);
	priority_queue<loc> pq;
	const long long MOD = 1e9 + 7;
	pq.push({0, -1, 0});
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		if (vis[t.x] && d[t.x] < t.d) continue;
		
		if (t.l != -1) {
			c[t.x] += c[t.l];
			c[t.x] %= MOD;
			mini[t.x] = min(mini[t.x], mini[t.l] + 1);
			maxi[t.x] = max(maxi[t.x], maxi[t.l] + 1);
		}
		if (vis[t.x]) continue;
		vis[t.x] = true;
		d[t.x] = t.d;
		for (auto n : v[t.x]) {
			pq.push({n.first, t.x, t.d + n.second});
		}
	}
	cout << d[n - 1] << " " << c[n - 1] << " " << mini[n - 1] << " " << maxi[n - 1] << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
