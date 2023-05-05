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


long long MOD = 0;

struct mi { // WARNING: needs some adjustment to work with FFT
 	long long v; explicit operator int() const { return v; } 
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


vector<mi> fact(5001);
vector<mi> invf(5001);

mi nCr(long long n, long long r) {
	return fact[n] * invf[n - r] * invf[r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		long long n, p;
		cin >> n >> p;
		MOD = p;
		vector<mi> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		fact[0] = 1;
		invf[0] = 1;
		for (int i = 1; i <= 5000; i++) {
			fact[i] = fact[i - 1] * i;
			invf[i] = invf[i - 1] / i;
		}
		long long t = n / 2;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (j >= t || i - j - 1 >= t) continue;
				//cout << j << " " << i - j - 1 << " " << i << endl;
				dp[i] += dp[j] * dp[i - j - 1] * nCr(i - 1, j);
			}
		}

		mi res = 0;
		for (int i = t; i < n; i++) {
			int left = n - i - 2;
			for (int j = 0; j <= max(left, 0); j++) {
				//cout << i << " " << j << endl;
				res += dp[i] * nCr(max(left, 0), j) * nCr(i + j - 1, j) * fact[j];
			}
 		}

		res *= n;
		res += dp[n];
		cout << res.v << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
