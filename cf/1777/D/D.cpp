#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

// 50% chance to be odd next round if nonzero children
// each step sum of non 

// t = total nodes
// number of leaf nodes = l... then 2^(t - 1) * t on step 0 
// on step 1... t - l nodes left in the tree.

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */

const long long MOD = 1e9 + 7;

struct mi { // WARNING: needs some adjustment to work with FFT
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, long long p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

int dfs(int x, vector<vector<int> > & v, vector<int> & h, set<int> & vis) {

	if (vis.find(x) != vis.end()) return 0;
	vis.insert(x);
	int d = 1;
	for (int i = 0; i < v[x].size(); i++) {
		d = max(d, 1 + dfs(v[x][i], v, h, vis));
	}
	h[x] = d;
	//cout << x << " " << h[x] << endl;
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		// t0 = 0.5 * n * 2^n
		// 
		int n;
		cin >> n;

		vector<mi> two(n + 1, 0);
		two[0] = 1;
		for (int i = 1; i <= n; i++) {
			two[i] = two[i - 1] * 2;
		}

		// 
		vector<vector<int> > v(n);
		for (int i = 0; i < n - 1; i++) {
			int u, x;
			cin >> u >> x;
			u--;
			x--;
			v[u].push_back(x);
			v[x].push_back(u);

		}
		//cout << "HUH" << endl;
		vector<int> h(n, 0);
		set<int> vis;
		dfs(0, v, h, vis);
		vector<int> cnt(n + 1, 0);
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			//cout << i << " " << h[i] << endl;
			maxi = max(h[i], maxi);
		}
		for (int i = 0; i < n; i++) {
			cnt[h[i]]++;
		}
		mi res = 0;
		long long left = n;
		for (int i = 1; i <= maxi; i++) {
			res += two[n - 1] * left;
			left -= cnt[i];
			//cout << i << " " << cnt[i] << endl;
		}
		cout << res.v << endl;
		

		
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
