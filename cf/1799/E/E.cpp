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


void fix(vector<string> & g, int n, int m) {
	for (int i = 0; i < n; i++) {
		int low = 1e6;
		int high = -1;
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '#') {
				low = min(low, j);
				high = max(high, j);
			}
		}
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '.') {
				if (j >= low && j <= high) g[i][j] = '#';
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int low = 1e6;
		int high = -1;
		for (int i = 0; i < n; i++) {
			if (g[i][j] == '#') {
				low = min(low, i);
				high = max(high, i);
			}
		}
		for (int i = 0; i < n; i++) {
			if (g[i][j] == '.') {
				if (i >= low && i <= high) g[i][j] = '#';
			}
		}
	}
}

void dfs(int y, int x, vector<string> & g, vector<vector<int> > & comps, int cur) {
	if (g[y][x] != '#') return;
	if (comps[y][x]) return;
	comps[y][x] = cur;
	vector<vector<int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (auto dir : dirs) {
		if (dir[0] + y >= g.size() || dir[0] + y < 0 || dir[1] + x >= g[0].size() || dir[1] + x < 0) continue;
		dfs(dir[0] + y, dir[1] + x, g, comps, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<string> g(n);
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		vector<string> orig = g;
		fix(g, n, m);
		fix(g, n, m);
		int indi = -1;
		int indj = -1;
		int cnt = 1;
		vector<vector<int > > comps(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '#' && !comps[i][j]) {
					dfs(i, j, g, comps, cnt++);
				}
			}
		}
		if (cnt == 3) {
			int ind1x, ind2x, ind1y, ind2y;
			vector<vector<int> > bounds(3, vector<int>(4, -1));
			for (int j = 0; j < 3; j++) {
				bounds[j][2] = 1e9;
				bounds[j][3] = 1e9;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (comps[i][j]) {
						//cout << i << " " << j << " " << comps[i][j] << endl;
						bounds[comps[i][j]][0] = max(i, bounds[comps[i][j]][0]);
						bounds[comps[i][j]][1] = max(j, bounds[comps[i][j]][1]);
						bounds[comps[i][j]][2] = min(i, bounds[comps[i][j]][2]);
						bounds[comps[i][j]][3] = min(j, bounds[comps[i][j]][3]);
					}
				}
			}
			//cout << bounds[1][0] << " " << bounds[1][2] << " " << bounds[2][0] << " " << bounds[2][2] << endl;
			if (bounds[1][2] > bounds[2][0]) {
				ind1y = bounds[1][2];
				ind2y = bounds[2][0];
			} else {
				ind1y = bounds[1][0];
				ind2y = bounds[2][2];
			}
			// if max > min
			if (bounds[1][3] > bounds[2][1]) {
				ind1x = bounds[1][3];
				ind2x = bounds[2][1];
			} else {
				ind1x = bounds[1][1];
				ind2x = bounds[2][3];
			}
			//cout<< ind1y << " " << ind1x << " " << ind2y << " " << ind2x << endl;
			vector<vector<pair<int, int> > > v(n, vector<pair<int, int> >(m, {-1, -1}));
			queue<pair<int, int> > q;
			q.push({ind1y, ind1x});
			vector<vector<int> > dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
			pair<int, int> inv = {-1, -1};
			set<pair<int, int> > vis;
			
			while (!q.empty()) {
				pair<int, int> t = q.front();
				q.pop();
				if (t.first == ind2y && t.second == ind2x) break;
				//cout << t.first << " " << t.second << endl;
				for (auto d : dirs) {
					if (t.first + d[0] < 0 || t.first + d[0] >= n || t.second + d[1] < 0 || t.second + d[1] >= m) continue;
					pair<int, int> next = {t.first + d[0], t.second + d[1]};
					//cout << next.first << " " << next.second << endl;
					if (vis.find(next) != vis.end()) continue;
					vis.insert(next);
					v[next.first][next.second] = {t.first, t.second};
					q.push(next);
				}
			}
			//cout << "HUH" << endl;
			
			while (ind2y != ind1y || ind2x != ind1x) {
				g[ind2y][ind2x] = '#';
				//cout << ind2y << " " << ind2x << endl;
				pair<int, int> next = v[ind2y][ind2x];
				ind2y = next.first;
				ind2x = next.second;
			}
			g[ind2y][ind2x] = '#';
		}
		fix(g, n, m);
		fix(g, n, m);
		int res = 0;
		for (int i = 0; i < n; i++) {
			cout << g[i] << endl;
		}
		cout << endl;
		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
