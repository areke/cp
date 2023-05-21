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

	vector<set<int> > r(n);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
		r[y].insert(x);
	}
	bool can = true;
	for (int i = 1; i < n - 1; i++) {
		if (v[i].size() != r[i].size()) can = false;
	}
	if (v[0].size() != r[0].size() + 1) can = false;
	if (v[n - 1].size() + 1 != r[n - 1].size()) can = false;
	vector<int> res;
	dfs(0, v, res);
	if (!can || res.size() != m + 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	reverse(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] + 1 << " \n"[i == res.size() - 1];
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
