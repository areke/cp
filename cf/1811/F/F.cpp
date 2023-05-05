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

void dfs(int x, vector<vector<int> > & v, set<int> & vis, set<int> & four, set<int> & comp, set<pair<int, int> > & edge) {
	if (vis.find(x) != vis.end()) return;
	vis.insert(x);
	comp.insert(x);
	for (int n : v[x]) {
		if (four.find(x) != four.end()) {
			if (four.find(n) == four.end()) {
				edge.insert({min(x, n), max(x, n)});
				dfs(n, v, vis, four, comp, edge);
			}
		} else {
			edge.insert({min(x, n), max(x, n)});
			dfs(n, v, vis, four, comp, edge);
		}
	}
}

void dfs1(int x, vector<vector<int> > & v, set<int> & con) {
	if (con.find(x) != con.end()) return;
	con.insert(x);
	for (int n : v[x]) {
		dfs1(n, v, con);
	}
}

bool checkCycle(set<int> & comp, vector<vector<int> > & v) {
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
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
		set<int> four;
		bool can = true;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].size() == 4) four.insert(i);
			else if (v[i].size() != 2) can = false;
		}
		set<int> con;
		dfs1(0, v, con);
		if (con.size() != n) can = false;
		int k = four.size();
		set<int> vis;
		set<pair<int, int> > fedge;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (four.find(i) != four.end() && four.find(v[i][j]) != four.end()) {
					fedge.insert({min(i, v[i][j]), max(i, v[i][j])});
				}
			}
		}
		if (fedge.size() != k) can = false;
		int kc = 0;
		for (int i = 0; i < n; i++) {
			if (vis.find(i) != vis.end()) continue;
			set<int> comp;
			set<pair<int, int> > edge;
			dfs(i, v, vis, four, comp, edge);
			if (comp.size() != k) can = false;
			int fc = 0;
			for (int n : comp) {
				if (four.find(n) != four.end()) fc++;
			}
			if (edge.size() != k) can = false;
			if (fc != 1) can = false;
			kc++;
		}
		if (kc != k) can = false;
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
