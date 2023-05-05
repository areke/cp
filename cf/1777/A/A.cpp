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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;

	// second half first half is ((n-1)+(n-2)+...(1)) * (n!)

	// 1 2 3
	// 1 3 2
	// 2 1 3
	// 2 3 1
	// 3 1 2
	// 3 2 1
	// n * f(n - 1) + (n - 1) * n / 2


	while (tests--) {
		// consider x, there are 1 	
		long long n;
		cin >> n;
		mi cur = 0;
		for (int i = 1; i <= n; i++) {
			cur += i * cur + i * (i - 1) / 2;
		}
		mi fact = 1;
		for (int i = 1; i <= n; i++) {
			fact *= i;
		}
		mi next =  (n - 1) * n / 2;
		fact *= next;
		mi res = cur + fact;
		cout << res.v << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
