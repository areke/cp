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


const long long MOD = 998244353;

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



void solve(int x, int d, vector<vector<int> > & v, vector<int> & p, vector<mi> & dis, int last) {

	dis[x] = d;
	p[x] = last;
	for (int n : v[x]) {
		if (n == last) continue;
		solve(n, d + 1, v, p, dis, x);
	}
}

void solvep(int x, int t, vector<mi> & prob, vector<vector<int> > & v, vector<int> & p, int last) {
	if (last != -1 && prob[x].v != 1) {
		prob[x] = prob[p[x]] / 2;
	}
	if (x == t) return;
	for (int n : v[x]) {
		if (n == last) continue;
		solvep(n, t, prob, v, p, x);
	}
}

void dfs(int x, int c, vector<int> & closest, vector<vector<int> > & v) {
	if (closest[x] != -1) return;
	closest[x] = c;
	for (int n : v[x]) {
		dfs(n, c, closest, v);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s, t;
	cin >> n >> s >> t;

	s--;
	t--;
	vector<vector<int> > v(n);
	for (int i = 0; i < n -1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<mi> dis(n, 0);
	
	vector<int> p(n);
	solve(t, 0, v, p, dis,  -1);
	vector<mi> prob(n, 0);
	prob[t] = 1;
	set<int> path;
	vector<int> closest(n, -1);
	int st = s;
	while (st != t) {
		closest[st] = st;
		path.insert(st);
		prob[st] = 1;
		st = p[st];
	}
	closest[t] = t;
	path.insert(t);
	for (int i : path) {
		for (int j : v[i]) {
			dfs(j, i, closest, v);
		}
	}
	

	vector<mi> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = mi(v[i].size()) * mi(dis[closest[i]]);
	}
	res[t] = 1;
	for (int i = 0; i < n; i++) {
		cout << res[i].v << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
