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

void kosaraju_dfs(int x, vector<vector<int> > & v, vector<bool> & vis, vector<int> & postorder) {
	if (vis[x]) return;
	vis[x] = true;
	for (int n : v[x]) {
		kosaraju_dfs(n, v, vis, postorder);
	}
	postorder.push_back(x);
}

void kosaraju_dfs2(int x, int cur, vector<vector<int> > & v, vector<int> & comp) {
	if (comp[x]) return;
	comp[x] = cur;
	for (int n : v[x]) {
		kosaraju_dfs2(n, cur, v, comp);
	}
}

vector<int> kosaraju(vector<vector<int> > & v, vector<vector<int> > & r) {
	int n = v.size();
	vector<bool> vis(n, 0);
	vector<int> postorder;
	for (int i = 0; i < n; i++) {
		kosaraju_dfs(i, v, vis, postorder);
	}
	vector<int> comp(n, 0);
	int cnt = 1;
	reverse(postorder.begin(), postorder.end());

	for (int i : postorder) {
		if (!comp[i]) {
			kosaraju_dfs2(i, cnt++, r, comp);
		}
	}
	return comp;
}

void dfs(int x, vector<vector<int> > & v, set<int> & vis, vector<int> & comp, vector<int> & cycle, vector<int> & path) {
	if (cycle.empty() && path.size() && x == path.front()) {
		cycle = path;
	}
	if (vis.count(x)) return;
	path.push_back(x);
	vis.insert(x);
	for (int n : v[x]) {
		if (comp[n] != comp[x]) continue;
		dfs(n, v, vis, comp, cycle, path);
	}
	path.pop_back();
}

bool color(int x, int col, vector<vector<int> > & v, set<int> & vis, vector<int> & comp, vector<int> & cols, long long t) {
	if (vis.count(x)) {
		return col == cols[x];
	}
	vis.insert(x);
	cols[x] = col;
	bool can = true;
	for (int n : v[x]) {
		if (comp[n] != comp[x]) continue;
		can = can && color(n, (col + 1) % t, v, vis, comp, cols, t);
	}
	return can;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<int> primes(2e5 + 1, 0);
	for (int i = 2; i <= 2e5; i++) {
		if (primes[i]) continue;
		primes[i] = 1;
		for (int j = 2 * i; j <= 2e5; j += i) {
			primes[j] = 2;
		}
	}
	vector<vector<int> > v(n);
	vector<vector<int> > r(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		r[y].push_back(x);
	}
	
	vector<int> comp = kosaraju(v, r);

	set<int> vis;
	vector<int> cols(n, -1);
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (!vis.count(i)) {
			vector<int> cycle;
			vector<int> path;
			dfs(i, v, vis, comp, cycle, path);
			if (cycle.empty()) continue;
			assert(cycle.size() > 1);
			set<int> cand;
			for (int j = 1; j * j <= cycle.size(); j++) {
				if (cycle.size() % j == 0) {
					if (primes[j] == 1) {
						cand.insert(j);
					}
					if (primes[cycle.size() / j] == 1) {
						cand.insert(cycle.size() / j);
					}
				}
			}
			
			long long l = 1;
			for (int x : cand) {
				long long c = x;
				long long best = 1;
				
				while ((long long) cycle.size() % c == 0) {
					set<int> vis2;
					bool can = color(i, 0, v, vis2, comp, cols, c);
					if (can) best = c;
					else break;
					c *= x;
				}
				l *= best;
			}
			assert(l <= cycle.size() && !cand.empty());
			set<int> vis2;
			bool nc = color(i, 0, v, vis2, comp, cols, l);
			assert(nc);
			map<int, long long> mp;
			for (int j : vis2) {
				assert(cols[j] != -1);
				mp[cols[j]]++;
			}
			if (k % l == 0) {
				for (int j = 0; j < l; j++) {
					res += mp[j] * (mp[j] - 1) / 2 + mp[j];
				}
			}
			if (l % 2 == 0 && k % l == l / 2) {
				for (int j = 0; j < l / 2; j++) {
					res += mp[j] * mp[j + l / 2];
				}
			}

		}
		
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
