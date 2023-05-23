#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v(n);

	vector<int> c(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
		c[x]++;
		c[y]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 1) {
			q.push(i);
		}
	}
	vector<bool> vis(n, 0);
	set<int> used;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (vis[t]) continue;
		vis[t] = true;
		for (int n : v[t]) {
			if (used.find(n) == used.end() && used.find(t) == used.end()) {
				used.insert(n);
				used.insert(t);
			}
			c[n]--;
			if (c[n] == 1) {
				q.push(n);
			}
		}
	}
	cout << used.size() / 2 << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
