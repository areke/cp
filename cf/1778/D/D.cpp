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

const long long MOD = 998244353;

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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int d = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) d++;
		}
		vector<mi> x(n + 1, 0);
		vector<mi> y(n + 1, 0);
		x[0] = 1;
		y[0] = 1;
		for (int i = 1; i < n; i++) {
			//cout << i << endl;
			mi c = mi(1) / (1 - (i * x[i - 1]) / n);
			//cout << "c" << endl;
			x[i] = mi(n - i) / mi(n) * c;
			//cout << "X" << endl;
			y[i] = (mi(i) * y[i - 1] / n + 1) * c;
			//cout << "Y" << endl;
		}
		vector<mi> res(n + 1, 0);
		res[n] = 0;
		for (int i = n - 1; i >= 0; i--) {
			res[i] = x[i] * res[i + 1] + y[i];
		}
		cout << res[d].v << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
