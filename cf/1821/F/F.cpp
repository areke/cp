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

long long MAXI = 8e5;
vector<mi> fact(MAXI);
vector<mi> ifact(MAXI);

mi nCr(long long n, long long r) {
	return fact[n] * ifact[n - r] * ifact[r]; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fact[0] = 1;
	for (long long i = 1; i < MAXI; i++) {
		fact[i] = fact[i - 1] * i;
	}

	ifact[MAXI - 1] = mi(1) / fact[MAXI - 1];
	for (long long i = MAXI - 2; i >= 0; i--) {
		ifact[i] = ifact[i + 1] * (i + 1);
	}
	
	long long n, m, k;
	cin >> n >> m >> k;
	mi res = 0;
	for (int i = 0; i <= m + 1; i++) {
		if (2 * i - 1 > m + 1) continue;
		long long small = i;
		long long big = i - 1;
		if (i == 0) {
			big = 0;
		}
		long long med = m + 1 - big - small;
		
		long long s = small * 1 + (2 * k + 2) * big + (k + 1) * med;
		if (med < 0) continue;
		if (n + 1 - s < 0) continue;
		mi mult = 1;
		if (i > 0) {
			mult = nCr(m + 1, 2 * i - 1);
		}
		res += nCr(n + 1 - s + m, m) * mult;
		
	}


	cout << res.v << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
