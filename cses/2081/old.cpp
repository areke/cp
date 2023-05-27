#include <bits/stdc++.h>
using namespace std;
 
const long long MAX_N = 2e5 + 5;
vector<vector<int> > v;
int n, k1, k2;
int s[MAX_N];
long long a[MAX_N];
long long b[MAX_N];
long long b2[MAX_N];
int rem[MAX_N];
long long res = 0;
 
int dfs(int x, int last) {
	s[x] = 1;
	for (int & n : v[x]) {
		if (rem[n] || n == last) continue;
		s[x] += dfs(n, x);
	}
	return s[x];
}
 
int get_centroid(int x, int sz, int last) {
	for (int & n : v[x]) {
		if (rem[n] || n == last) continue;
		if (s[n] > sz / 2) return get_centroid(n, sz, x);
	}
	return x;
}
 
void solve(int x, int last, int dist, long long* av, int sz) {
	if (dist > k2) return;
	av[dist]++;
	for (int & n : v[x]) {
		if (rem[n] || n == last) continue;
		solve(n, x, dist + 1, av, sz);
	}
}	
 
void decomp(int x, int lastc) {
	int sz = s[x];
	int c = get_centroid(x, sz, -1);
	fill(a, a + sz, 0);
	if (k1 > sz) return;
	solve(c, -1, 0, a, sz);
	auto children = v[c];
	a[0] = 0;
	if (true) {
		for (int j = sz - 2; j >= 0; j--) {
			a[j] += a[j + 1];
		}
	} else {
		for (int j = 1; j < sz; j++) {
			a[j] += a[j - 1];
		}
	}
	
	int yc = 0;
	for (int y : children) {
		if (rem[y]) continue;
		
		int nsz =dfs(y, c) + 1;
		fill(b, b + nsz, 0);
 
		fill(b2, b2 + nsz, 0);
		solve(y, c, 1, b, nsz);
		long long tot = 0;
		if (true) {
			b2[nsz - 1] = b[nsz - 1];
			for (int j = nsz - 2; j >= 0; j--) {
				b2[j] = b2[j + 1] + b[j];
			}
		} else {
			b2[0] = b[0];
			tot += (sz - nsz) * (nsz);
			for (int j = 1; j < nsz; j++) {
				b2[j] = b2[j - 1] + b[j];
			}
		}
		
		for (int j = 0; j < nsz; j++) {
			if (true) {
				if (j >= k1) {
				res += 2 * b[j];
				}
				if (j >= k2) {
					res -= 2 * b[j];
				}
				if (k1 - j < sz) {
					int ind = max(k1 - j, 0);
					int amnt = 0;
					if (ind < nsz) amnt = b2[ind];
					res += b[j] * (a[ind] - amnt);
				}
				if (k2 - j < sz) {
					int ind = max(k2 - j, 0);
					int amnt = 0;
					if (ind < nsz) amnt = b2[ind];
					res -= b[j] * (a[ind] - amnt);
				}
			} else {
				int lk = k1 - 1;
				if (j > lk) break;
				tot -= 2 * b[j];
				tot -= a[lk - j] * b[j];
			}
			
		}
		
	}
	rem[c] = 1;
	for (int n : children) {
		if (rem[n]) continue;
		decomp(n, c);
	}
}
 
void compute() {
	dfs(0, -1);
	decomp(0, -1);
}
 
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k1 >> k2;
	v.resize(n);
 	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	k2++;
	compute();
	cout << res / 2 << endl;
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}