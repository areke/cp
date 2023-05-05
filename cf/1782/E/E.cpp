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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, q;
		cin >> n >> q;
		mi p = mi(q) / mi(10000);

		vector<vector<mi> > dp(2 * n + 5, vector<mi>(2 * n + 5, 0));
		vector<mi> pv(n + 2, 0);
		int cons = n + 1;

		for (int k = 0; k < n; k++) {

			vector<vector<mi> > next(2 * n + 5, vector<mi>(2 * n + 5, 0));
			vector<mi> nextp(2 * n + 5, 0);
			for (int i = 0; i < 2 * k + 1; i++) {
				for (int j = 0; j < n; j++) {
					next[i + 1][j + 1 + cons] += p * dp[i][j + cons] / mi(2 * k + 1);
					next[i + 1][j - 1 + cons] += (1 - p) * dp[i][j + cons] / mi(2 * k + 1);
					next[i + 2][j + cons] += dp[i][j + cons] / mi(2 * k + 1);
				}
			}
			dp = next;
			for (int i = 2 * k; i >= 0; i--) {
				if (i >= 1) {
					nextp[i] += mi(i) / mi(2 * k + 1) * pv[i - 1];
				}
				nextp[i] += mi(2 * k - i) / mi(2 * k + 1) * pv[i];
				nextp[i] += mi(1) / mi(2 * k + 1) * p;
			}
			pv = nextp;
		}
		vector<vector<mi> > res(2 * n + 5, vector<mi>(2 * n + 5, 0));
		for (int i = 0; i < 2 * n + 1; i++) {
			for (int j = 0; j <= n; j++) {
				res[i + 1][j + 1] += res[i][j] * pv[i];
				if (j != 0) {
					res[i + 1][j - 1] += res[i][j] * (1 - pv[i]);
				}
			}
		}
		mi ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += res[2 * n][i];
		}
		cout << ans.v << endl;


	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
