#include <bits/stdc++.h>
using namespace std;

vector<set<int> > s;
vector<int> res;
void dfs(int x, vector<vector<int> > & v, vector<int> & c, int last = -1) {
	s[x] = {c[x]};
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, v, c, x);
		if (s[x].size() < s[n].size()) swap(s[x], s[n]);
		for (int y : s[n]) {
			s[x].insert(y);
		}
	}
	res[x] = s[x].size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> c(n);
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	s.resize(n);
	int x, y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	res.resize(n);
	dfs(0, v, c);
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
