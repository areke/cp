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


const long long MOD = 1000000007;

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
mi modpow(mi a, long long p) { assert(p >= 0); // won't work for negative p
	return p==0?1:modpow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return modpow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

mi dfs(int x, vector<vector<int> > & e, set<int> & vis, vector<mi> & h, vector<int> & b, int last, long long BASE) {
	if (vis.find(x) != vis.end()) return 0;
	vis.insert(x);
	b[x] = last;
	mi res = 1;
	for (int i = 0; i < e[x].size(); i++) {
		res += BASE * dfs(e[x][i], e, vis, h, b, x, BASE);
	}
	return h[x] = res;
}

void dfs2(int x, vector<vector<int> > & e, set<int> & vis, vector<mi> & dp, vector<mi> & h, vector<int> & b, long long BASE) {
	if (vis.find(x) != vis.end()) return;
	vis.insert(x);
	dp[x] = h[x];
	if (b[x] != -1) {
		dp[x] += BASE * (dp[b[x]] - BASE * h[x]);
	}
	for (int i = 0; i < e[x].size(); i++) {
		dfs2(e[x][i], e, vis, dp, h, b, BASE);
	}
}

set<int> solve(int n, vector<long long> & v, vector<vector<int> > & e, long long BASE) {

	set<int> vis;
	vector<mi> h(n, 0);
	vector<mi> dp(n, 0);
	vector<int> b(n, 0);
	dfs(0, e, vis, h, b, -1, BASE);
	vis.clear();
	dfs2(0, e, vis, dp, h, b, BASE);
	set<long long> s;
	mi hash = 0;
	for (int i = 0; i < n - 1; i++) {
		hash += modpow(BASE, v[i]);
	}
	for (int i = 0; i < n; i++) {
		s.insert((hash + modpow(BASE, i)).v);
	}
	set<int> res;
	for (int i = 0; i < dp.size(); i++) {
		if (s.find(dp[i].v) != s.end()) res.insert(i + 1);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	vector<vector<int> > e(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vector<long long> BASE = {998244353, 5, 7};
	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i );
	}
	for (int i = 0; i < 3; i++) {
		set<int> res = solve(n, v, e, BASE[i]);
		for (int x = 1; x <= n; x++) {
			if (res.find(x) == res.end()) {
				if (s.find(x) != s.end()) s.erase(s.find(x));
			}
		}
	}
	
	cout << s.size() << endl;
	for (int  i : s) {
		cout << i << " ";
	}
	cout << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
