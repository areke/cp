#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n);
	vector<vector<int> > r(n);
	vector<int> deg(n, 0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		r[y].push_back(x);
		deg[x]++;
	}
	vector<bool> vis(n, 0);
	vector<int> d(n, 1e9);
	priority_queue<pair<int, int> > pq;
	pq.push({0, n - 1});
	while (!pq.empty()) {
		pair<int, int> t = pq.top();
		pq.pop();
		
		if (vis[t.second]) continue;

		vis[t.second] = true;
		d[t.second] = -t.first;
		for (int u : r[t.second]) {
			pq.push({t.first - 1 - (deg[u] - 1), u});
			deg[u]--;
		}
	}
	int res = d[0];
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
