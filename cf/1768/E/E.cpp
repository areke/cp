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

long long MOD = 1e9 + 7;

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


vector<mi> fact;
vector<mi> ifact;



mi nCr(long long n, long long k) {
	//cout << n << " " << k << " " << fact[n].v << " " << fact[k].v << endl;
	return fact[n] / fact[k] / fact[n - k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		// 0 if permutation is sorted... 1
		// 1 if exactly one of first n or last n is sorted... 2*2n! - 1
		// 3 if both have each others' numbers
		// 2 if exactly one has each others' number 


		// both dont have each others'
			// 

		// 3n! permutations total.
		long long n, m;
		cin >> n >> m;
		fact.resize(3 * n + 1);
		ifact.resize(3 * n + 1);
		MOD = m;
		fact[0] = 1;
		ifact[0] = 1;
		for (long long i = 1; i <= 3 * n; i++) {
			fact[i] = fact[i - 1] * i;
		}
		mi zero = 1;
		mi one = 2 * fact[2 * n] - fact[n] - 1;
		mi two = 0;
		for (int i = 0; i <= n; i++) {
			two += nCr(n, i) * nCr(n, i) * fact[n] * fact[i] * fact[2*n - i];
		}
		for (int i = 1; i <= n; i++) {
			two += 2 * nCr(n, i) * nCr(2 * n - i, n) * fact[n] * fact[i] * fact[2 * n - i];
		}
		two -= (one + zero);
		mi three = fact[3 * n] - zero - one - two;
		mi res = one + two * mi(2) + three * mi(3);
		//cout << zero.v << " " << one.v << " " << two.v << " " << three.v << endl;
		cout << res.v << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
