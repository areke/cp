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
 
void getc(int x, vector<vector<int> > & v, vector<vector<int> > & children, vector<int> & p, int last) {
	p[x] = last;
	for (int n : v[x]) {
		if (n != last) {
			children[x].push_back(n);
			getc(n, v, children, p, x);
		}
	}
}
 
void solve(int x, vector<vector<int> > & v, vector<int> & path, vector<vector<int> > & c, vector<int> & p, vector<bool> & vis, int last) {
	if (x == -1) return;
	if (vis[x]) return;
	vis[x] = true;
	bool found = false;
	path.push_back(x);
	for (int n : c[x]) {
		if (c[n].size()) {
			found = true;
			solve(c[n][0], v, path, c, p, vis, last);
		}
	}
	if (!found && !c[x].empty()) {
		solve(c[x][0], v, path, c, p, vis, last);
	}
	if (p[x] != -1) {
		for (int n : c[p[x]]) {
			if (n == x) continue;
			solve(n, v, path, c, p, vis, last);
		}
	}
	solve(p[x], v, path, c, p, vis, last);
	if (p[x] != -1) {
		solve(p[p[x]], v, path, c, p, vis, last);
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
	vector<vector<int> > children(n);
	vector<int> parents(n, -1);
	getc(0, v, children, parents, -1);
	solve(0, v, path, children, parents, vis, -1);
	bool can = path.size() == n;
	if (path.size() > 1) {
		bool ok = false;
		int l = path[path.size() - 1];
		for (int x : children[0]) {
			if (x == l) ok = true;
			for (int n : children[x]) {
				if (n == l) ok = true;
			}
		}
		can = can && ok;
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