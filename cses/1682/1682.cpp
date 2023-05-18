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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n);

	vector<vector<int> > r(n);
	set<pair<int, int> > s;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		s.insert({x, y});
		r[y].push_back(x);
	}
	
	auto [comp, post] = kosaraju(v, r);
	bool can = true;
	for (int i = 0; i < n; i++) {
		if (comp[post[i]] != comp[post[0]]) {
			can = false;
			cout << "NO" << endl;
			cout << post[i] + 1 << " " << post[0] + 1 << endl;
			break;
		}	
	}
	if (can) {
		cout << "YES" << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
