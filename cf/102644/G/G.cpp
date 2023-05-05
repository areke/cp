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

vector<vector<mi> > mult(vector<vector<mi> > & a, vector<vector<mi> > & b) {
	vector<vector<mi> > res(a.size(), vector<mi>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			for (int k = 0; k < b[0].size(); k++) {
				res[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	return res;
}

vector<vector<mi> > mexp(vector<vector<mi> > & v, long long n) {
	if (n == 0) return {{1, 0}, {0, 1}};
	if (n == 1) return v;
	vector<vector<mi> > res(v.size(), vector<mi>(v[0].size()));
	res = mexp(v, n / 2);
	res = mult(res, res);
	if (n % 2) {
		res = mult(res, v);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n + 3);
	vector<long long> c(n + 3);
	for (int i = 0; i < n; i++) {
		cin >> a[n - i - 1];
	}
	a[n] = 1;
	a[n + 1] = n;
	a[n + 2] = n * n;
	for (int i = 0; i < n + 3; i++) {
		cin >> c[i];
	}
	vector<vector<mi> > cur(n + 3, vector<mi>(1, 0));
	for (int i = 0; i < n + 3; i++) {
		cur[i][0] = a[i];
	}
	vector<vector<mi> > trans(n + 3, vector<mi>(n + 3, 0));
	for (int i = 0; i < n + 3; i++) {
		trans[0][i] = c[i];
	}

	for (int i = 1; i < n; i++) {
		trans[i][i - 1] = 1;
	}
	for (int i = n; i < n + 3; i++) {
		trans[i][i] = 1;
	}
	trans[n + 1][n] = 1;
	trans[n + 2][n] = 1;
	trans[n + 2][n + 1] = 2;
	if (k < n) {
		cout << a[n - k - 1] << endl;
		return 0 ;
	}
	k -= (n - 1);
	vector<vector<mi> > M = mexp(trans, k);
	cout << mult(M, cur)[0][0].v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
