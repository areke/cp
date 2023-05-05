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
#include <unordered_map>
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

vector<mi> dp(2e5 + 1);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	vector<mi> res(2e5 + 1, 0);
	dp[0] = 1;
	for (int i = k, q = k; q <= n; q += i, i++) {
		vector<mi> mod(i + 1, 0);
		for (int j = 0; j <= n; j++) {
			res[j] += mod[j % (i)];
			mi last = mod[j % (i)];
			mod[j % (i)] += dp[j];
			dp[j] = last;

		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i].v;
		if (i == n) cout << endl;
		else cout << " ";
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
