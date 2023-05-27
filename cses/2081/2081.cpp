#include <bits/stdc++.h>
using namespace std;
 
const long long MAX_N = 2e5 + 5;
vector<vector<int> > v;
int n, k1, k2;
int s[MAX_N];
int p[MAX_N];
long long a[MAX_N];
long long b[MAX_N];
long long b2[MAX_N];
long long csz[MAX_N];
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
	if (dist > k2 ||(sz < k2 && dist >= k1)) return;
	av[dist]++;
	for (int & n : v[x]) {
		if (rem[n] || n == last) continue;
		solve(n, x, dist + 1, av, sz);
	}
}	
int cnt = 0;
 
void decomp(int x, int lastc) {
	cnt++;
	int sz = s[x];
	
	int c = get_centroid(x, sz, -1);
	csz[c] = sz;
	fill(a, a + sz, 0);
	if (k1 > sz) return;
	solve(c, -1, 0, a, sz);
	auto children = v[c];
 
	a[0] = 0;
	if (sz >= k2) {
		for (int j = sz - 2; j >= 0; j--) {
			a[j] += a[j + 1];
		}
	} else {
		for (int j = 1; j < sz; j++) {
			a[j] += a[j - 1];
		}
	}
	
	int yc = 0;
	long long tot = 0;
	for (int y : children) {
		if (rem[y]) {
			continue;
		}
		
		
		
		int nsz = dfs(y, c) + 1;
		if (sz < k2) {
			tot += ((long long)sz - (nsz - 1)) * ((long long)nsz-  1) + nsz - 1;
		}
		fill(b, b + nsz, 0);
 
		fill(b2, b2 + nsz, 0);
		solve(y, c, 1, b, sz);
		
		assert(nsz - 1 <= sz);
		if (sz >= k2) {
			b2[nsz - 1] = b[nsz - 1];
			for (int j = nsz - 2; j >= 0; j--) {
				b2[j] = b2[j + 1] + b[j];
			}
		} else {
			b2[0] = b[0];
			
			for (int j = 1; j < nsz; j++) {
				b2[j] = b2[j - 1] + b[j];
			}
		}
		
		for (int j = 0; j < nsz; j++) {
			if (sz >= k2) {
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
				long long amt = b2[nsz - 1];
				long long aamt = a[sz - 1];
				if (lk - j < sz) aamt = a[lk - j];
				if (lk - j < nsz) {
					amt = b2[lk - j];
				}
				tot -= 2 * b[j];
				tot -= (aamt - amt) * b[j];
			}
		}
	}
	//
 
	res += tot;
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