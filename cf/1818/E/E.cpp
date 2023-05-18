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




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long d;
	cin >> d;
	long long n = d;
	vector<mi> fact(d + 1);
	vector<mi> ifact(d + 1);
	fact[0] = 1;
	for (int i = 1; i <= d; i++) {
		fact[i] = fact[i - 1] * mi(i);
	}
	ifact[d] = mi(1) / fact[d];
	for (int i = d - 1; i >= 0; i--) {
		ifact[i] = ifact[i + 1] * mi(i + 1);
	}
	vector<mi> a(d + 1);
	vector<mi> b(d + 1);
	for (int i = 0; i < d + 1; i++) {
		long long x;
		cin >> x;
		a[i] = x;
	}
	for (int i = 0; i < d + 1; i++) {
		long long x;
		cin >> x;
		b[i] = x;
	}
	vector<mi> c(n + 1);
	for (int i = 0; i <= n; i++) {
		c[i] = ifact[i] * ifact[n - i];
		if ((n - i) % 2) c[i] *= mi(-1);
	}
	mi k = 0;
	for (int i = 0; i <= n; i++) {
		k += c[i] * a[i];
	}
	mi ax = 0;
	mi bx = 0;
	for (int i = 0; i <= n; i++) {
		ax += a[i] * c[i] * mi(-1) * mi(n * (n + 1) / 2 - i);
	}
	for (int i = 0; i <= n; i++) {
		bx += b[i] * c[i] * mi(-1) * mi(n * (n + 1) / 2 - i);
	}
	cout << ((bx - ax) / mi(n) / mi(k)).v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
