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
 
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
 
	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
 
	bool same_set(int a, int b) { return get(a) == get(b); }
 
	int size(int x) { return -e[get(x)]; }
 
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};
 
 
void dfs(int x, vector<vector<int> > & e, DSU & d, set<int> & vis, vector<vector<int> > & dsue, vector<int> & l) {
	if (vis.find(x) != vis.end()) return;
	
	if (vis.find(d.get(x)) == vis.end()) {

		vis.insert(x);
		dfs(d.get(x), e, d, vis, dsue, l);
		for (int v : dsue[d.get(x)]) {
			dfs(v, e, d, vis, dsue, l);
		} 
	}
	vis.insert(x);
	for (int v : e[x]) {
		dfs(v, e, d, vis, dsue, l);
	}
	l.push_back(x);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > e(n);
		map<long long, vector<pair<int, int> > > w;
		for (int i = 0; i < m; i++) {
			int u, v, ww;
			cin >> u >> v >> ww;
			u--;
			v--;
			w[ww].push_back({u, v});
			e[u].push_back(v);
		}
		long long low = 0;
		long long high = 1e9;
		long long res = -1;
		while (low <= high) {
			long long mid = (low + high) / 2;
			DSU dsu(n);
			bool b = false;
			for (auto it : w) {
				if (it.first > mid) break;
				for (auto x : it.second) {
					dsu.unite(x.first , x.second);
				}
			}
			set<int> vis;
			vector<vector<int> > dsue(n);
			for (int i = 0; i < n; i++) {
				dsue[dsu.get(i)].push_back(i);
			}
			vector<int> res1;
			for (int i = 0; i < n; i++) {
				dfs(i, e, dsu, vis, dsue, res1);
			}
			int cand = res1[res1.size() - 1];
			vis.clear();
			dfs(cand, e, dsu, vis, dsue, res1);
			if (vis.size() == n) {
				res = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
 
		}
		cout << res << endl;
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}