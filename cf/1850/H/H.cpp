#include <bits/stdc++.h>
using namespace std;

bool solve(int x, long long cur, vector<vector<pair<int, int> > > & v, vector<bool> & vis, vector<long long> & c) {
	if (vis[x]) {
		return cur == c[x];
	}
	c[x] = cur;
	vis[x] = true;
	bool ok = true;
	for (auto n : v[x]) {
		ok &= solve(n.first, cur + n.second, v, vis, c);
	}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int> > > v(n);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			v[a].push_back({b, -c});
			v[b].push_back({a, c});
		}
		vector<bool> vis(n, 0);
		vector<long long> c(n, 0);
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) can &= solve(i, 0, v, vis, c);
		}
		if (can) {
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
