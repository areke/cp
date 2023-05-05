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

int best = 0;

map<pair<int, int>, int> res;

void dfs(int x, int e, vector<vector<int> > & v, set<int> & vis, vector<int> & path) {
	if (vis.find(x) != vis.end() || vis.find(e) != vis.end()) return;
	vis.insert(x);
	path.push_back(x);
	if (x == e) return;
	for (int n : v[x]) {
		dfs(n, e, v, vis, path);
	}
	if (vis.find(e) != vis.end()) return;
	path.pop_back();
}

void dfs2(int x, set<int> banned, vector<vector<int> > & v, set<int> & vis) {
	if (vis.find(x) != vis.end()) return;
	vis.insert(x);
	for (int n : v[x]) {
		if (banned.find(n) == banned.end()) dfs2(n, banned, v, vis);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	vector<pair<int, int> > order(n - 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
		order[i] = {min(x, y), max(x, y)};
	}
	//cout << "HM" << endl;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> good;
	
	set<int> maybe;
	map<int, int> m;
	for (int x : a) {
		m[x]++;
	}
	//cout << "UH" << endl;
	for (auto x : m) {
		if (x.second >= 3) good.insert(x.first);
		else if (x.second == 2) maybe.insert(x.first);
	}
	int maxi = 0;
	best = good.empty() ? 0 : *(good.rbegin());
	if (!maybe.empty()) {
		int high = *(maybe.rbegin());
		maxi = max(best, max(maxi, high));
		if (best < high) {
			int s = -1, e = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] == high && s== - 1) s = i;
				else if (a[i] == high && s != -1) e = i; 
			}
			vector<int> path;
			set<int> vis;
			dfs(s, e, v, vis, path);
			set<int> l, r;
			dfs2(s, {path[1]}, v, l);
			dfs2(path[1], {s}, v, r);
			set<int> al, ar;
			for (int x : l) {
				if (maybe.find(a[x]) != maybe.end()) al.insert(a[x]);
			}
			for (int x : r) {
				if (maybe.find(a[x]) != maybe.end()) ar.insert(a[x]);
			}
			set<int> maybel;
			for (int x : al) {
				if (ar.find(x) == ar.end()) maybel.insert(x);
			}
			for (int x : ar) {
				if (al.find(x) == al.end()) maybel.insert(x);
			}
			for (int i = 1; i < path.size(); i++) {
				set<int> move;
			
				int highest = maybel.empty() ? 0 : *(maybel.rbegin());
				res[{min(path[i - 1], path[i]), max(path[i - 1], path[i])}] = max(best, highest);
				
				if (i < path.size() - 1) {
					dfs2(path[i], {path[i - 1], path[i + 1]}, v, move);

					for (int x : move) {
						if (maybe.find(a[x]) == maybe.end()) continue;
						if (maybel.find(a[x]) == maybel.end()) {
							maybel.insert(a[x]);	
						} else {
							maybel.erase(maybel.find(a[x]));
						}
					}
				}
				
			}
		}
		
	}
	
	
	//cout << "COOL" << endl;
	for (auto it : order) {
		if (res.count(it)) {
			cout << res[it] << endl;
		} else {
			cout << maxi << endl;
		}
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
