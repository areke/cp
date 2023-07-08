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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;



const long long MOD = 998244353;

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

const int MAXN = 10000000 + 5;
mi fact[MAXN], invfact[MAXN];

mi nCr(int n, int r) {
	return fact[n] * invfact[r] * invfact[n - r];
}

void prepareFact() {
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i;
	}
	invfact[MAXN - 1] = mi(1) / fact[MAXN - 1];
	for (int i = MAXN - 2; i >= 0; i--) {
		invfact[i] = invfact[i + 1] * (i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prepareFact();
	long long n, aa, x, y, m, k;
	cin >> n >> aa >> x >> y >> m >> k;
	vector<long long> a(n);
	a[0] = aa;
	for (int i = 1; i < n; i++) {
		a[i] = (a[i - 1] * x + y) % m;
	}
	vector<mi> b(n, 0);
	vector<vector<mi> >  p(k + 1, vector<mi>(n, 0));
	for (int i = k - 1; i < n; i++) {	
		p[0][i] = ((i > 0) ? p[0][i - 1] : 0) + a[i - k + 1];
		for (int j = 1; j <= k; j++) {
			p[j][i] = p[j - 1][i - 1] + ((i > 0) ? p[j][i - 1] : 0);
		}
	}
	vector<long long> c(n, 0);
	for (int i = 1; i <= n; i++) {
		c[i - 1] = p[k][i - 1].v * ((long long)(i)); 
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res ^= c[i];
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
