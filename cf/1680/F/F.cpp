#include <bits/stdc++.h>
using namespace std;
 
 
vector<int> depth;
vector<int> p;
vector<pair<int, int> > edges;
vector<vector<int> > t;
vector<vector<int> > v;
set<long long> sp;
set<int> vis;
set<long long> used;
vector<int> c;
vector<int> good;
vector<int> bad;

long long hsh(int x, int y) {
	if (x > y) swap(x, y);
	long long a = x;
	a = a << 30;
	a += y;
	return a;
}

void get_dfs_tree(int x) {
	vis.insert(x);
	for (int n : v[x]) {
		if (vis.count(n)) continue;
		if (used.count(hsh(n, x))) continue;
		used.insert(hsh(n, x));
		t[x].push_back(n);
		sp.insert(hsh(n, x));
		depth[n] = depth[x] + 1;
		p[n] = x;
		get_dfs_tree(n);
	}
}
 
 
void color(int x, int col) {
	if (c[x] != -1) return;
	c[x] = col;
	for (int n : t[x]) {
		color(n, col ^ 1);
	}
}


void color2(int x, int col, pair<int, int> & skip) {
	if (c[x] != -1) return;
	c[x] = col;
	for (int n : v[x]) {
		if ((x == skip.first && n == skip.second) || (n == skip.first && x == skip.second)) continue;
		color2(n, col ^ 1, skip);
	}
}

int bt = 0;

void solve(int i) {
	int g = 0, b = 0;
	for (int n : t[i]) {
		solve(n);
		g += good[n];
		b += bad[n];
	}
	for (int n : v[i]) {
		if (sp.count(hsh(n, i))) {
			continue;
		}
		if (c[i] == c[n]) {
			if (edges.size() == 0) edges.push_back({i, n});
			if (depth[n] >= depth[i]) {
				b--;
			} else {
				bt++;
				b++;
			}
		} else {
			if (depth[n] >= depth[i]) {
				g--;
			} else {
				g++;
			}
		}
	}
	bad[i] = b;
	good[i] = g;
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		depth.clear();
		edges.clear();
		sp.clear();
		p.clear();
		int n, m;
		cin >> n >> m;
		p.assign(n, 0);
		depth.assign(n, 0);
		v.clear();
		t.clear();
		v.resize(n);
		t.resize(n);
		c.clear();
		bad.clear();
		good.clear();
		c.assign(n, -1);
		bad.assign(n, 0);
		good.assign(n, 0);


		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		get_dfs_tree(0);

		used.clear();
		vis.clear();
		color(0, 1);
		bt = 0;
		solve(0);
		if (bt == 0) {
			cout << "YES" << endl;
			string res = "";
			for (int i = 0; i < n; i++) {
				res += '0' + c[i];
			}
			cout << res << endl;
			continue;
		} else {
			bool found = false;
			pair<int, int> e;
			if (bt == 1) {
				found = true;
				e = edges[0];
			} else {
				for (int i = 1; i < n; i++) {
					if (bad[i] == bt && good[i] == 0) {
						e = {p[i], i};
						found = true;
						break;
					}
				}
			}
			if (found) {
				// << e.first << " " << e.second << endl;
				c.assign(n, -1);
				color2(e.first, 1, e);
				color2(e.second, 1, e);
			} else {
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			string res = "";
			for (int i = 0; i < n; i++) {
				res += '0' + c[i];
			}
 
			cout << res << endl;
		}
 
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}