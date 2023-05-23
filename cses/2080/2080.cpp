#include <bits/stdc++.h>
using namespace std;

// solves https://codeforces.com/problemset/problem/342/E

struct centroid_decomp {
	int n, k;
	vector<unordered_set<int> > v;
	vector<int> s;
	vector<int> p;
	long long res = 0;

	centroid_decomp(vector<unordered_set<int> > v, int k) {
		n = v.size();
		this->k = k;
		this->v = v;
		s.assign(n, 0);
		p.assign(n, -1);
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

	void solve(int x, int last, int dist, unordered_map<int, long long> & m) {
		m[dist]++;
		for (int n : v[x]) {
			if (n == last) continue;
			solve(n, x, dist + 1, m);
		}
	}

	void decomp(int x, int lastc) {
		int sz = dfs(x, -1);
		int c = get_centroid(x, sz, -1);

		p[c] = lastc;
		auto children = v[c];
		vector<unordered_map<int, long long> > l(children.size());
		unordered_map<int, long long> all;
		int ind = 0;
		for (int y : children) {
			solve(y, c, 1, l[ind]);
			for (auto it : l[ind]) {
				all[it.first] += it.second;
			}
			ind++;
		}
		for (int i = 0; i < l.size(); i++) {
			for (auto it : l[i]) {
				res += it.second * (all[(k - it.first)] - l[i][(k - it.first)]);
				if (it.first == k) res += 2 * it.second;
			}
		}

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

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<unordered_set<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].insert(y);
		v[y].insert(x);
	}
	centroid_decomp decomp(v, k);
	decomp.compute();
	cout << decomp.res / 2 << endl;
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}