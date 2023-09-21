#include <bits/stdc++.h>
using namespace std;


int dfs(int x, vector<vector<int> > & v, map<vector<int>, int> & m, vector<int> & dp, int last = -1) {
	vector<int> children = {};
	for (int n : v[x]) {
		if (n == last) continue;
		children.push_back(dfs(n, v, m, dp ,x));
	}
	sort(children.begin(), children.end());
	if (m.count(children)) {
		dp[x] = m[children];
		return m[children];
	}

	m[children] = m.size();
	dp[x] = m[children];
	//cout << x << " " << dp[x] << endl;
	return m[children];
}

bool solve(int x, vector<vector<int> > & v, map<vector<int>, int> & m, vector<int> & dp, int last = -1) {
	map<int, vector<int> > children;
	for (int n : v[x]) {
		if (n == last) continue;
		children[dp[n]].push_back(n);
	}
	vector<int> need;
	for (auto it : children) {
		if (it.second.size() % 2) {
			need.push_back(it.second[0]);
		}
	}
	if (need.size() == 0) return true;
	if (need.size() == 1) {
		return solve(need[0], v,m ,dp, x);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}	
		vector<int> dp(n, 0);
		map<vector<int>, int> m;
		dfs(0, v, m, dp);

		if (solve(0, v, m, dp)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
