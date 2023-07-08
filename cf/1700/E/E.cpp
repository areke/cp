#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > dirs = {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}, {0, 0}};

bool solve(vector<vector<int> > & v, vector<pair<int, int> > & mp) {
	int n = v.size();
	int m = v[0].size();
	vector<bool> pos(n * m + 1, 0);
	pos[1] = 1;
	bool can = true;
	int first = 0;
	int last = 0;
	for (int i = 1; i <= n * m; i++) {
		if (!pos[i]) {
			can = false;
			first = i;
			break;
		}
		for (auto & dir : dirs) {
			pair<int, int> next = {dir[0] + mp[i].first, dir[1] + mp[i].second};
			if (next.first < 0 || next.first >= n) continue;
			if (next.second < 0 || next.second >= m) continue;
			pos[v[next.first][next.second]] = 1;
		}
	}
	return can;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(m, 0));
	vector<pair<int, int> > mp(n * m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			mp[v[i][j]] = {i, j};
		}
	}
	int val = 1;
	set<int> pos;
	pos.insert(1);
	bool can = true;
	int first = 0;
	int last = 0;
	for (int i = 1; i <= n * m; i++) {
		if (!pos.count(i)) {
			can = false;
			first = i;
			break;
		}
		for (auto dir : dirs) {
			pair<int, int> next = {dir[0] + mp[i].first, dir[1] + mp[i].second};
			if (next.first < 0 || next.first >= n) continue;
			if (next.second < 0 || next.second >= m) continue;
			pos.insert(v[next.first][next.second]);
		}
	}
	pos = {n * m};
	for (int i = n * m; i >= 1; i--) {
		if (!pos.count(i)) {
			can = false;
			last = i;
			break;
		}
		for (auto dir : dirs) {
			pair<int, int> next = {dir[0] + mp[i].first, dir[1] + mp[i].second};
			if (next.first < 0 || next.first >= n) continue;
			if (next.second < 0 || next.second >= m) continue;
			pos.insert(v[next.first][next.second]);
		}
	}
	vector<pair<int, int> > a;
	vector<pair<int, int> > b;
	for (auto dir : dirs) {
		pair<int, int> next = {dir[0] + mp[first].first, dir[1] + mp[first].second};
		if (next.first < 0 || next.first >= n) continue;
		if (next.second < 0 || next.second >= m) continue;
		a.push_back(next);
	}
	for (auto dir : dirs) {
		if (first -1 < 1) break;
		pair<int, int> next = {dir[0] + mp[first - 1].first, dir[1] + mp[first - 1].second};
		if (next.first < 0 || next.first >= n) continue;
		if (next.second < 0 || next.second >= m) continue;
		a.push_back(next);
	}
	for (auto dir : dirs) {
		pair<int, int> next = {dir[0] + mp[last].first, dir[1] + mp[last].second};
		if (next.first < 0 || next.first >= n) continue;
		if (next.second < 0 || next.second >= m) continue;
		b.push_back(next);
	}
	for (auto dir : dirs) {
		if (last + 1 > n * m) break;
		pair<int, int> next = {dir[0] + mp[last + 1].first, dir[1] + mp[last + 1].second};
		if (next.first < 0 || next.first >= n) continue;
		if (next.second < 0 || next.second >= m) continue;
		b.push_back(next);
	}
	set<pair<int, int> > s;
	for (int i = 0; i < a.size(); i++) {
		auto next = a[i];
		for (int j = 0; j < b.size(); j++) {
			auto next2 = b[j];
			swap(v[next.first][next.second], v[next2.first][next2.second]);
			swap(mp[v[next.first][next.second]], mp[v[next2.first][next2.second]]);
			if (solve(v, mp)) {
				int mm = min(v[next.first][next.second], v[next2.first][next2.second]);
				int nn = max(v[next.first][next.second], v[next2.first][next2.second]);;
				s.insert({mm, nn});
			}
			swap(mp[v[next.first][next.second]], mp[v[next2.first][next2.second]]);
			swap(v[next.first][next.second], v[next2.first][next2.second]);
		}
	}
	if (can) {
		cout << 0 << endl;
	} else if (s.size()) {
		cout << 1 << " " << s.size() << endl;
	} else {
		cout << 2 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
