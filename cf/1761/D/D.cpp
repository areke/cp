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
#include <complex>
#include <cstring>
#include <cmath>
using namespace std;
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
 
 
vector<mi> fact(1e6 + 1, 1);
vector<mi> invf(1e6 + 1, 1);
vector<mi> three(1e6 + 1, 1);
 
mi nCr(long long n, long long r) {
	return fact[n] * invf[r] * invf[n - r];
}
 
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		long long n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
			invf[i] = invf[i - 1] / i;
			three[i] = three[i - 1] * 3;
		}
		if (k == 0) {
			cout << three[n].v << endl;
			continue;
		}
		mi res = 0;
		for (int i = 1; i <= k; i++) {
			// choose x_1, ... x_i such that x_1 + ... + x_i = k
			// and x_1 ... >= 1
			// = (i - 1 + k - (i)) C (i - 1) * 3^(k - i)
 
			// choose y_1,... y_{i} such that y_1,... y_i = n - k
			// and y_1 ... >= 1
			// = (n - k  - i + i - 1) C (i - 1) 
			// = (n - k - 1) C (i - 1) * 
 
			// y_1, ... y_{i - 1} 
			// = (n - k - 2) C (i - 2) * (3^(i))
			
			mi carries = nCr(k - 1, i - 1) * three[k - i];
			if (i >= 2 && n - k - i + 1 >= 0) {
				res += nCr(n - k - 1, i - 2) * three[n - k - i + 1] * carries;
			}
			if (n - k - i >= 0) {
				res += nCr(n - k - 1, i - 1) * three[n - k - i] * carries;
				res += nCr(n - k - 1, i - 1) * three[n - k - i] * carries * 3;
			}
			if (n - k - i - 1 >= 0) {
				res += nCr(n - k - 1, i) * three[n - k - i - 1] * carries * 3;
			}
		}
		cout << res.v << endl;
		
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}