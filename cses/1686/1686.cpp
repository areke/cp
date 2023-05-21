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

pair<vector<int>, vector<int> > kosaraju(vector<vector<int> > & v, vector<vector<int> > & r) {
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
	return {comp, postorder};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<long long> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
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
	auto [comp, post] = kosaraju(v, r);
	map<int, long long> mw;
	for (int i = 0; i < n; i++) {
		mw[comp[i]] += w[i];
	}

	vector<vector<int> > rc(n + 1);
	for (int i = 0; i < n; i++) {
		for (int j : r[i]) {
			if (comp[i] != comp[j]) rc[comp[i]].push_back(comp[j]);
		}
	}
	set<int> s;
	vector<int> top;
	for (int i = 0; i < post.size(); i++) {
		if (s.find(comp[post[i]]) == s.end()) {
			top.push_back(comp[post[i]]);
		}
		s.insert(comp[post[i]]);
	}
	vector<long long> dp(top.size() + 1, 0);
	long long res = 0;
	for (int i = 0; i < top.size(); i++) {
		dp[top[i]] = mw[top[i]];
		for (int j : rc[top[i]]) {
			dp[top[i]] = max(dp[top[i]], dp[j] + mw[top[i]]);
		}
		res = max(res, dp[top[i]]);
	}
	cout << res << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
