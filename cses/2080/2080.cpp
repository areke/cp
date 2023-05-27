#include <bits/stdc++.h>
using namespace std;
  
struct centroid_decomp {
	int n, k;
	vector<vector<int> > v;
	vector<int> s;
	vector<int> p;
	vector<int> a, b;
	vector<int> rem;
	long long res = 0;
	centroid_decomp(vector<vector<int> > & v, int k) {
		n = v.size();
		this->k = k;
		this->v = v;
		rem.assign(n, 0);
		s.assign(n, 0);
		p.assign(n, -1);
		a.assign(n, 0);
		b.assign(n, 0);
	}
 
	int dfs(int x, int last) {
		s[x] = 1;
		for (int n : v[x]) {
			if (rem[n]) continue;
			if (n == last) continue;
			s[x] += dfs(n, x);
		}
		return s[x];
	}
 
	int get_centroid(int x, int sz, int last) {
		for (int n : v[x]) {
			if (rem[n]) continue;
			if (n == last) continue;
			if (s[n] > sz / 2) return get_centroid(n, sz, x);
		}
		return x;
	}
 
	void solve(int x, int last, int dist, vector<int> & av) {
		av[dist]++;
		if (dist > k) return;
		for (int n : v[x]) {
			if (rem[n]) continue;
			if (n == last) continue;
			solve(n, x, dist + 1, av);
		}
	}
 
	void decomp(int x, int lastc) {
		int sz = dfs(x, -1);
		int c = get_centroid(x, sz, -1);
		fill(a.begin(), a.begin() + sz, 0);
		if (k > sz) return;
		solve(c, -1, 0, a);
		p[c] = lastc;
		auto children = v[c];
		a[0] = 0;
		
		int yc = 0;
		for (int y : children) {
			if (rem[y]) continue;
			
			int nsz = min(n, dfs(y, c) + 1);
			fill(b.begin(), b.begin() + nsz, 0);
			solve(y, c, 1, b);
			for (int j = 0; j < nsz; j++) {
				if (j > k) break;
				if (j == k) {
					res += 2 * b[j];
					continue;
				}
				if (k - j >= sz) continue;
				int amnt = 0;
				if (k - j < nsz) amnt = b[k - j];
				res += b[j] * (a[k - j] - amnt);
			}
		}
		rem[c] = 1;
		
 
		for (int n : children) {
			if (rem[n]) continue;
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
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	centroid_decomp decomp(v, k);
	decomp.compute();
	cout << decomp.res / 2 << endl;
	
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}