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

// https://codeforces.com/blog/entry/82953
mi lagrange_interpolate(long long p, vector<mi> & x, vector<mi> & y) {
	assert(x.size() == y.size());
	
	int n = x.size();
	
	int d = n - 1;
	for (int i = 1; i < n; i++) {
		assert(x[i] - x[i - 1] == 1);
	}
	vector<mi> ifact(d + 1);
	mi f = 1;
	for (int i = 1; i <= d; i++) {
		f *= mi(i);
	}
	ifact[d] = mi(1)  / f;
	for (int i = d - 1; i >= 0; i--) {
		ifact[i] = ifact[i + 1] * mi(i + 1);
	}
	mi num = 1;
	for (int i = 0; i <= d; i++) {
		num *= mi(p - x[i]);
	}

	mi res = 0;
	for (int i = 0; i <= d; i++) {
		mi c = y[i] * ifact[i] * ifact[d - i];
		if ((d - i) % 2) c *= mi(-1);
		c *= num / mi(p - x[i]);
		res += c;
	}
	return res;
}

mi mexp(long long n, long long k) {
	if (k == 0) return 1;
	mi res = mexp(n, k / 2);
	res *= res;
	if (k % 2) res *= n;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;

	vector<mi> x(k + 2);
	vector<mi> y(k + 2);
	mi cur = 0;
	for (long long i = 1; i <= k + 2; i++) {
		cur += mexp(i, k);
		x[i - 1] = i;
		y[i - 1] = cur;
	}
	if (n <= k + 2) {
		cout << y[n - 1].v << endl;
	} else {
		cout << lagrange_interpolate(n, x, y).v << endl;
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
