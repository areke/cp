#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<vector<int> > & v, int last, vector<int> & level, vector<int> & p) {
	if (x == 0) {
		level[x] = 0;
	} else {
		level[x] = level[last] + 1;
		p[x] = last;
	}
	for (int n : v[x]) {
		dfs(n, v, x, level);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> level(n, 0);
	vector<int> p(n, -1);

	dfs(0, v, -1, level, p);

	for (int i = 0; i < q; i++) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		x--;
		y--;
		vector<int> f;
		vector<int> l;
		while (x != y) {
			if (level[x] < level[y]) {
				l.push_back(x);
				y = p[y];
			}
			else {
				f.push_back(y);
				x = p[x];
			}
			x = p[x];
		}
		f.push_back(x);
	}

		// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
