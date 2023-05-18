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
	vector<vector<int> > v(n);

	vector<vector<int> > r(n);

	vector<int> c(n, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		r[y].push_back(x);
		c[y]++;
	}
	bool can = true;
	vector<int> res;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!c[i]) q.push(i);
	}
	while (!q.empty()) {
		int t = q.front();
		res.push_back(t);
		q.pop();
		for (int j : v[t]) {
			c[j]--;
			if (c[j] == 0) q.push(j);
		}
	}
	if (res.size() != n) {
		cout << "IMPOSSIBLE" << endl;
	}  else {
		for (int i = 0; i < n; i++) {
			cout << res[i] + 1 << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
