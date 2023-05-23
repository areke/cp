#include <bits/stdc++.h>
using namespace std;

long long dfs(int x, vector<vector<int> > & v, vector<long long> & c, int last) {
	c[x] = 1;
	for (int n : v[x]) {
		if (n == last) continue;
		c[x] += dfs(n, v, c, x);
	}
	return c[x];
}

long long dfs2(int x, vector<vector<int> > & v, vector<long long> & c, vector<long long> & d, int last) {
	d[x] = c[x] - 1;
	for (int n : v[x]) {
		if (n == last) continue;
		d[x] += dfs2(n, v, c, d, x);
	}
	return d[x];
}

long long solve(int x, vector<vector<int> > & v, vector<long long> & c, vector<long long> & e, int last) {
	if (last != -1) {
		e[x] = e[last] + (int)v.size() - 2 * c[x];
	}
	for (int n : v[x]) {
		if (n == last) continue;
		solve(n, v, c, e, x);
	}
	return e[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	vector<long long> c(n, 0);
	vector<long long> d(n, 0);
	vector<long long> e(n, 0);
	dfs(0, v, c, -1);
	dfs2(0, v, c, d, -1);
	e[0] = d[0];
	solve(0, v, c, e, -1);
	for (int i = 0; i < n; i++) {
		cout << e[i] << " \n"[i == n - 1];
	}
	



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
