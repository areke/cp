#include <bits/stdc++.h>
using namespace std;

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

	vector<long long> res(n + 1, 1e18);

	for (int i = 0; i < n; i++) {
		queue<pair<int, int> > q;
		q.push({i, 0});
		int cnt = 0;
		vector<bool> vis(n, 0);
		long long cur = 0;
		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			if (vis[x.first]) continue;
			vis[x.first] = true;
			cnt++;
			cur += x.second;
			res[cnt] = min(res[cnt], cur);
			
			for (int n : v[x.first]) {
				q.push({n, x.second + 1});
			}
		}
	}
	res[0] = 0;
	for (int i = 0; i <= n; i++) {
		cout << (long long)(n - 1) * i - 2 * res[i] << " \n"[i == n];
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
