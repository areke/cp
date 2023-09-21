#include <bits/stdc++.h>
using namespace std;


struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

bool dfs(int x, vector<vector<int> > & v, vector<int> & c, int cur) {
	if (c[x]) {
		return c[x] == (cur + 1);
	}
	c[x] = cur + 1;
	bool can = true;
	for (int n : v[x]) {
		can = can && dfs(n, v, c, cur ^ 1);
	}
	return can;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	
	
	for (int test = 1; test <= tests; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		DSU dsu(n + m);
		vector<vector<int> > v(n + m);
		vector<pair<int, int> > dif;
		for (int i = 0; i < k; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--;
			b--;
			c--;
			d--;
			if (d == b + 1) {
				dif.push_back({a, n + min(b, d)});
			} else {
				dsu.unite(a, n + min(b, d));
			}
		}
		for (int i = 0; i < dif.size(); i++) {
			int a = dsu.get(dif[i].first);
			int b = dsu.get(dif[i].second);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<int> c(n + m, 0);
		string res = "YES";
		for (int i = 0; i < n + m; i++) {
			if (!c[i]) { 
				bool can = dfs(i, v, c, 0);
				if (!can) {
					res = "NO";
					break;
				}
			}
		}
		cout << res << endl;

	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
