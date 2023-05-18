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
	int x, d, l;
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
	vector<vector<int> > v(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	priority_queue<loc> pq;
	pq.push({0, 0, 0});
	vector<int> last(n, -1);
	while (!pq.empty()) {
		loc t = pq.top();
		pq.pop();
		if (last[t.x] != -1) continue;
		last[t.x] = t.l;
		for (int x : v[t.x]) {
			pq.push({x, t.d + 1, t.x});
		}
	}
	if (last[n - 1] == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		int cur = n - 1;
		
		vector<int> res;
		res.push_back(cur);
		while (cur != 0) {
			cur = last[cur];
			res.push_back(cur);
		}
		reverse(res.begin(), res.end());
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << " \n"[i == res.size() - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
