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
 
pair<vector<int>, vector<int> > kosaraju(int n, vector<vector<int> > & v, vector<vector<int> > & r) {
	vector<bool> vis(2 * n);
	vector<int> postorder;
	for (int i = 0; i < 2 * n; i++) {
		kosaraju_dfs(i, v, vis, postorder);
	}
	vector<int> comp(2 * n, 0);
	int cnt = 1;
	reverse(postorder.begin(), postorder.end());
 
	for (int i : postorder) {
		if (!comp[i]) {
			kosaraju_dfs2(i, cnt++, r, comp);
		}
	}
	return {comp, postorder};
}
 
void rem(int x, vector<vector<int> > & v, set<int> & s) {
	if (s.find(x) != s.end()) return;
	s.insert(x);
	for (int n : v[x]) {
		rem(n, v, s);
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> m >> n;
	vector<vector<int> > v(2 * n);
	vector<vector<int> > r(2 * n);
 
	for (int i = 0; i < m; i++) {
		char c, d;
		int x, y;
		cin >> c >> x >> d >> y;
		int a = (c == '+');
		int b = (d == '+');
		x--;
		y--;
		v[x + n * (!a)].push_back(y + n * b);
		v[y + n * (!b)].push_back(x + n * a);
		r[y + n * b].push_back({x + n * (!a)});
		r[x + n * a].push_back({y + n * (!b)});
	}
	
	auto [comp, post] = kosaraju(n, v, r);
	set<int> s;
	vector<int> res(n, 0);
	bool can = true;
	vector<vector<int > > mp(2 * n + 1);
	for (int i = 0; i < n; i++) {
		if (comp[i] == comp[i + n]) {
			can = false;
		}
	}
	for (int i = 0; i < comp.size(); i++) {
		mp[comp[i]].push_back(i);
	}
	if (!can) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	vector<int> a;
	set<int> seen;
	for (int i = 0; i < post.size(); i++) {
		if (seen.find(comp[post[i]]) == seen.end()) {
			seen.insert(comp[post[i]]);
			a.push_back(comp[post[i]]);
		}
	}
	for (int i = a.size() - 1; i >= 0; i--) {
		for (auto it : mp[a[i]]) {
			if (s.find(it) == s.end()) {
				res[it % n] = it / n;
				rem({it % n +  ((it / n) ^ 1) * n}, r, s);
				s.insert(it);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (res[i] ? '+' : '-') << " \n"[i == n - 1];
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}