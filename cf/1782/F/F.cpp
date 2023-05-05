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

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */

const long long MOD = 998244353 ;

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

int cons = 0;


mi solve(int n, int s, vector<vector<mi> > & f, vector<vector<mi> > & g, vector<vector<bool> > & v, mi p) {
	if (v[n][s + cons]) return f[n][s + cons];
	mi res = 0;
	for (int i = 0; i < n; i++) {
		res += (mi(1) - p) * g[n][i] * solve(i, s + 1, f, g, v, p) * solve(n - i - 1, s, f, g, v, p);
		res += p * g[n][i] * solve(i, s - 1, f, g, v, p) * solve(n - i - 1, s, f, g, v, p); 
	}
	v[n][s + cons] = true;
	//cout << n << " " << s << " " << res.v << endl;
	return f[n][s + cons] = res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1; 
	while (tests--) {
		long long n, q;
		cin >> n >> q;
		mi p = q / mi(1e4);
		cons = n + 1;

		// probability that length inside left most sequence is k
		vector<vector<mi> > g(n + 1, vector<mi>(n + 1, 0));

		// probability after k operations sum >= s 
		vector<vector<mi> > f(2 * n + 5, vector<mi>(2 * n + 5, 0));
		vector<vector<bool> > v(2 * n + 5, vector<bool>(2 * n + 5, false));
		g[1][0] = 1;
		for (int i = 1; i < n; i++) {
			mi len = 2 * i + 1;
			for (int j = 0; j < i; j++) {
				g[i + 1][j] += g[i][j] * (len - 2 * j - 2) / len;
				g[i + 1][0] += g[i][j] / len;
				g[i + 1][j + 1] += (2 * j + 1) / len * g[i][j];
			}
		}
		for (int i = -n; i <= 0; i++) {
			f[0][i + cons] = 1;
			v[0][i + cons] = true;
		}
		cout << solve(n, 0, f, g, v, p).v << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
