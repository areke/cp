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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

void dfs(int x, int s, vector<set<int> > & v, set<int> & vis, vector<int> & path, vector<int> & cycle) {
	if (vis.find(x) != vis.end()) return;
	if (cycle.size()) return;
	vis.insert(x);
	path.push_back(x);
	if (path.size() > 2 && v[x].find(s) != v[x].end()) {
		cycle = path;
		cycle.push_back(s);
		return;
	}
	for (int n : v[x]) {
		dfs(n, s, v, vis, path, cycle);
	}
	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
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
		set<pair<int, int> > e;
		for (int i = 0; i < n; i++) {
			if (e.size()) break;
			if (v[i].size() >= 4) {
				vector<int> cycle;
				vector<int> path;
				set<int> vis;
				dfs(i, i, v, vis, path, cycle);
				if (cycle.size()) {
					for (int j = 1; j < cycle.size(); j++) {
						e.insert({cycle[j - 1], cycle[j]});
					}
					int cnt = 0;
					for (int j : v[i]) {
						if (cnt == 2) break;
						if (e.find({i, j}) == e.end() && e.find({j, i}) == e.end()) {
							e.insert({i, j});
							cnt++;
						}
					}
				}
			}
		}
		if (e.empty()) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
			cout << e.size() << "\n";
			for (auto edge : e) {
				cout << edge.first + 1 << " " << edge.second + 1 << "\n";
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
