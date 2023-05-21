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

int dfs(int x, vector<vector<int> > & v, int last, bool & can, vector<int> & res, map<pair<int, int>, int> & m) {
	vector<int> c;
	for (int n : v[x]) {
		if (n == last) continue;
		int child = dfs(n, v, x, can, res, m);
		if (child) c.push_back(child);
	}
	//cout << x + 1<< " " << last  + 1 << " " << c.size() << endl;
	if (c.size() == 1 && c[0] == 2) {
		int ind = m[{last, x}];
		if (ind) res.push_back(ind);
		return 0;
	} else if (c.size() == 2 && c[0] == 1 && c[1] == 1) {
		int ind = m[{last, x}];
		if (ind) res.push_back(ind);
		return 0;
	} else if (c.size() == 1) {
		return c[0] + 1;
	} else if (c.size()) {
		can = false;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		map<pair<int, int>, int> m;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
			m[{x, y}] = i + 1;
			m[{y, x}] = i + 1;
		}
		bool can = true;
		vector<int> res;
		int c = dfs(0, v, -1, can, res, m);
		if (c != 0) can = false;
		if (can) {
			cout << res.size() << endl;
			for (int i  = 0; i < res.size(); i++) {
				cout << res[i] << " \n"[i == res.size() - 1];
			}
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
