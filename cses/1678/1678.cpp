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

vector<int> res;

void dfs(int x, vector<set<int> > & v, vector<bool> & vis, vector<int> & p, set<int> & c) {

	if (res.size()) return;
	if (vis[x]) return;
	p.push_back(x);
	if (p.size() > 1) {
		c.insert(p[p.size() - 2]);
	}
	for (int n : v[x]) {
		if (c.find(n) != c.end()) {
			int ind = -1;
			for (int i = 0; i < p.size(); i++) {
				if (p[i] == n) {
					ind = i;
					break;
				}
			}
			for (int i = ind; i< p.size(); i++) {
				res.push_back(p[i]);
			}
			return;
		}
	}
	
	
	vis[x] = true;
	for (int n : v[x]) {
		dfs(n, v, vis, p, c);
	}
	if (p.size() > 1) {
		c.erase(p[p.size() - 2]);
	}
	p.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<set<int> > v(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
	}
	vector<bool> vis(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vector<int> p;
			set<int> c;
			dfs(i, v, vis, p, c);
		}
	}
	if (res.size()) {
		cout << res.size() + 1 << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << " ";
		}
		cout << res[0] + 1 << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
