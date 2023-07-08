#include <bits/stdc++.h>
using namespace std;

long long INF = 2e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long> > > v(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		long long w;
		cin >> w;
		x--;
		y--;
		v[x].push_back({y, w});
		v[y].push_back({x, w});
	}
	priority_queue<pair<long long, long long> > pq;
	pq.push({0, 0});
	vector<bool> vis(n, 0);
	long long res = INF;
	vector<pair<string, long long> > ans;
	string cur = "";
	for (int i = 0; i < n; i++) {
		cur += '0';
	}
	bool finite = false;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		if (vis[top.second]) continue;
		vis[top.second] = true;
		cur[top.second] = '1';
		ans.push_back({cur, -top.first});
		if (top.second == n - 1) {
			finite = true;
			break;
		}
		for (int i = 0; i < v[top.second].size(); i++) {
			auto nxt = v[top.second][i];
			pq.push({top.first - nxt.second, nxt.first});
		}
	}
	if (finite) {
		cout << ans[ans.size() - 1].second << " " << ans.size() - 1 << endl;
		for (int i = 0; i < ans.size() - 1; i++) {
			long long minutes = ans[i + 1].second - ans[i].second;
			cout << ans[i].first << " " << ans[i + 1].second - ans[i].second << endl;
		}
	} else {
		cout << "inf" << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
