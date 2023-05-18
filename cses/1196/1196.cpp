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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, long long> > > v(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		v[x].push_back({y, w});
	}
	vector<multiset<long long> > d(n);
	priority_queue<loc> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		if (d[t.x].size() == k) continue;
		d[t.x].insert(t.d);
		for (auto n : v[t.x]) {
			pq.push({n.first, t.d + n.second});
		}
	}
	for (auto it : d[n - 1]) {
		cout << it << " ";
	}
	cout << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
