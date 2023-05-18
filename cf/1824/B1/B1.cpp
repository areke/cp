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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


const long long MOD = 1e9 + 7;

struct mi { // WARNING: needs some adjustment to work with FFT
 	long long v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v((int)(_v%MOD)) { v += (v<0)*MOD; }
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

mi dfs(int x, vector<vector<int> > & v, vector<mi> & c, int last) {
	mi res = 1;
	for (int n : v[x]) {
		if (n == last) continue;
		res += dfs(n, v, c, x);
	}
	return c[x] = res;
}

void dfs2(int x, mi & res, int d, vector<vector<int> > & v, int last) {
	res += d;
	for (int n : v[x]) {
		if (n == last) continue;
		dfs2(n, res, d + 1, v, x);
	}
}

void solve(int y, vector<vector<int> > & v, vector<mi> & c, vector<mi> & d, int x) {
	if (x != -1) {
		d[y] = d[x] + c[0] - c[y] - c[y]; 
	}
	for (int n : v[y]) {
		if (n == x) continue;
		solve(n, v, c, d, y);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
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
	if (k % 2 == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<mi> c(n, 0);
	dfs(0, v, c, -1);
	vector<mi> d(n, 0);
	dfs2(0, d[0], 0, v, -1);
	d[0] += n - 1;
	solve(0, v, c, d, -1);
	mi res = 0;
	for (int i = 0; i < n; i++) {
		res += d[i];
	}
	res = res / mi(n - 1) / mi(n);
	cout << res.v << endl;



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
