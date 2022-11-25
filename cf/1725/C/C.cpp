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

long long MOD = 998244353;

map<pair<long long, long long>, long long> dp;


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

long long modpow(long long b, long long p) {
	if (b == 0 && p == 0) return 1;
	if (b == 0) return 0;
	if (p == 0) return 1;
	long long res = 1;
	if (p % 2) {
		res *= b;
		res %= MOD;
	}
	long long half = modpow(b, p / 2);
	res *= half;
	res %= MOD;
	res *= half;
	res %= MOD;
	return res;
}

long long solve(long long x, long long p, long long m) {
	if (p == 0) {
		return modpow(m, x);
	}
	if (dp.count({p, m})) {
		return dp[{p, m}];
	}
	long long res = solve(x, p - 1, m) * m % MOD * (m - 1) % MOD;
	res += solve(x, p - 1, m - 1) * m;
	return dp[{p, m}] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> d(n);
		dp.clear();
		map<long long, int> ma;
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			cin >> d[i];
			cur += d[i];
			d[i] = cur;
			ma[cur] = i;
		}
		long long p = 0;
		if (cur % 2 == 0) {	
			for (int i = 0; i < n; i++) {
				if (ma.count(cur / 2 + d[i])) {
					p++;
				}
			}
		}
		long long x = n - 2 * p;
		mi res = 0;
		mi xx = 1;
		mi pp = 1;
		mi ii = 1;
		for (int i = 0; i <= p; i++) {
			// res += x * pow(x, p - i) * (x * (x - 1)) ^ (p - i);
			mi cur = xx * modpow(m - i, x);
			cur *= pp / ii;
			if (i != p) {
				if (m - i <= 0) continue;
				cur *= modpow((m - i) * (m - i - 1) % MOD, p - i);
			}
			//cout << i << " " << cur << endl;
			res += cur;
			xx *= (m - i);
			pp *= (p - i);
			ii *= (i + 1);
		}
		cout << res.v << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
