#include <bits/stdc++.h>
using namespace std;

// solves https://codeforces.com/problemset/problem/342/E

struct centroid_decomp {
	int n;
	vector<set<int> > v;
	vector<int> s;
	vector<int> p;
	vector<map<int, int> > d;
	vector<int> res;

	void precomp(int x, int last) {
		if (last != -1) res[x] = res[last] + 1;
		for (int n : v[x]) {
			if (n == last) continue;
			precomp(n, x);
		}
	}

	centroid_decomp(vector<set<int> > v) {
		n = v.size();
		this->v = v;
		s.assign(n, 0);
		p.assign(n, -1);
		d.resize(n);
		res.assign(n, 0);
		precomp(0, -1);
	}

	int dfs(int x, int last) {
		s[x] = 1;
		for (int n : v[x]) {
			if (n == last) continue;
			s[x] += dfs(n, x);
		}
		return s[x];
	}

	int get_centroid(int x, int sz, int last) {
		for (int n : v[x]) {
			if (n == last) continue;
			if (s[n] > sz / 2) return get_centroid(n, sz, x);
		}
		return x;
	}

	void solve(int x, int c, int last) {
		if (last != -1) d[c][x] = d[c][last] + 1;
		else d[c][x] = 0;
		for (int n : v[x]) {
			if (n == last) continue;
			solve(n, c, x);
		}
	}
	int cnt = 0;

	void decomp(int x, int lastc) {
		int sz = dfs(x, -1);
		int c = get_centroid(x, sz, -1);
		solve(c, c, -1);
		p[c] = lastc;
		set<int> children = v[c];

		for (int n : children) {
			v[n].erase(v[n].find(c));
			v[c].erase(v[c].find(n));
		}
		for (int n : children) {
			decomp(n, c);
		}
	}

	void compute() {
		decomp(0, -1);
	}

	void update(int x) {
		int orig = x;
		while (x != -1) {
			res[x] = min(res[x], d[x][orig]);

			x = p[x];
		}
	}

	int query(int x) {
		
		int best = 1e9;
		int orig = x;
		while (x != -1) {
			best = min(best, d[x][orig] + res[x]);

			x = p[x];
		}
		return best;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<set<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
		v[y].insert(x);
	}
	centroid_decomp decomp(v);
	decomp.compute();

	while (q--) {
		int t, x;
		cin >> t >> x;
		x--;
		if (t == 1)  {
			decomp.update(x);
		} else {
			cout << decomp.query(x) << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}