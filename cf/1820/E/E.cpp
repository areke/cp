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

int st = 0;

void dfs(int x, vector<vector<int> > & v, int last) {
	st = x;
	for (int n : v[x]) {
		if (n != last) dfs(n, v, x);
	}
}

void getc(int x, vector<vector<int> > & v, vector<set<int> > & children, vector<int> & p, int last) {
	p[x] = last;
	st = x;
	for (int n : v[x]) {
		if (n != last) {
			children[x].insert(n);
			getc(n, v, children, p, x);
		}
	}
}

void solve(int x, vector<vector<int> > & v, vector<int> & path, vector<set<int> > & c, vector<int> & p, vector<bool> & vis, int last) {
	if (x == -1) return;
	if (vis[x]) return;
	vis[x] = true;
	bool found = false;
	
	path.push_back(x);
	for (int n : c[x]) {
		if (c[n].size()) {
			found = true;
			solve(*(c[n].begin()), v, path, c, p, vis, last);
			break;
		}
	}
	if (!found && !c[x].empty()) {
		solve(*(c[x].begin()), v, path, c, p, vis, last);
	}
	if (p[x] != -1) {
		c[p[x]].erase(x);
		if (!c[p[x]].empty()) {
			int n = *(c[p[x]].begin());
			solve(n, v, path, c, p, vis, last);
		}
		if (c[p[x]].empty()) {
			if (!vis[p[x]]) solve(p[x], v, path, c, p, vis, last);
			else {
				solve(p[p[x]], v, path, c, p, vis, last);
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 0; i < n- 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	// start at any node, go down by 2 until we can't,
	vector<bool> vis(n, 0); 
	vector<int> path;
	vector<set<int> > children(n);
	vector<int> parents(n, -1);
	dfs(0, v, -1);
	getc(st, v, children, parents, -1);
	vector<set<int> > c = children;
	solve(st, v, path, children, parents, vis, -1);
	
	bool can = path.size() == n;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int x : c[i]) {
			if (c[x].size()) cnt++;
		}
		if (cnt > 3) can = false;
	}
	if (!can) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		bool cc = false;
		int a = path[i];
		int b = path[(i + n - 1) % n];
		for (int x : c[a]) {
			if (x == b) cc = true;
			for (int j : c[x]) {
				if (j == b) cc = true;
			}
		}
		swap(a, b);
		for (int x : c[a]) {
			if (x == b) cc = true;
			for (int j : c[x]) {
				if (j == b) cc = true;
			}
		}
		if (parents[a] == parents[b]) cc = true;
		if (!cc) can = false;
	}
	if (can) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			cout << path[i] + 1;
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	} else {
		cout << "No" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
