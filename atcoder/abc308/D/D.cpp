#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];

	}
	string x = "snuke";
	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = find(x.begin(), x.end(), s[i][j]) - x.begin();
		}
	}
	queue<pair<int, int> > q;
	q.push({0, 0});
	set<pair<int, int> > vis;
	vector<vector<int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (vis.count(t)) continue;
		vis.insert(t);
		for (auto & d : dirs) {
			if (t.first + d[0] < 0 || t.first + d[0] >= n) continue;
			if (t.second + d[1] < 0 || t.second + d[1] >= m) continue;
			pair<int, int> next = {t.first + d[0], t.second + d[1]};
			if ((v[t.first][t.second] + 1) % 5 == v[next.first][next.second]) {
				q.push(next);
			}
		}
	}
	if (vis.count({n - 1, m - 1})) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
