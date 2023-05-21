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


void dfs(int x, vector<set<int> > & v, vector<int> & res) {
	while (v[x].size()) {
		auto it = v[x].begin();
		v[x].erase(it);
		v[*it].erase(v[*it].find(x));
		dfs(*it, v, res);
	}
	res.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<set<int> > v(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
		v[y].insert(x);
	}
	bool can = true;
	for (int i = 0; i < n; i++) {
		if (v[i].size() % 2) can = false;
	}
	vector<int> res;
	dfs(0, v, res);

	if (!can || res.size() != m + 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] + 1 << " \n"[i == res.size() - 1];
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
