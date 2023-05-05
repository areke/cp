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

vector<mi> fact(5001, 0);

vector<mi> ifact(5001, 0);


mi nCr(long long n, long long r) {
	return fact[n] * ifact[r] * ifact[n - r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fact[0] = 1;
	ifact[0] = 1;
	for (long long i = 1; i <= 5000; i++) {
		fact[i] = fact[i - 1] * i;
		ifact[i] = mi(1) / fact[i];
	}
	int tests;
	cin >> tests;
	while (tests--) {
		int n, k;
		cin >> n >> k;
		vector<int> c(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		vector<pair<long long, mi> > dp(n + 1, {0, 0});
		dp[0] = {0, 1};
		for (int i = 1; i <= n; i++) {
			int cnt = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (cnt >= k) {
					if (dp[i].first == dp[j].first + 1) {
						dp[i].second += dp[j].second * nCr(cnt - 1, k -1);
					} else if (dp[j].first + 1 > dp[i].first) {
						dp[i] ={dp[j].first + 1, dp[j].second * nCr(cnt - 1, k -1)};
					}
				}
				if (j > 0) {
					if (c[j - 1] == c[i - 1]) {
						cnt++;
					} 
				}
			}
		}
		mi res = 0;
		long long maxi = 0;
		for (int i = 0; i <= n; i++) {
			maxi = max(dp[i].first, maxi);
		}
		for (int i = 0; i <= n; i++) {
			//cout << dp[i].first << " " << dp[i].second.v << endl;
			if (dp[i].first == maxi) {
				res += dp[i].second;
			}
		}
		cout << res.v << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
