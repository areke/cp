#include <bits/stdc++.h>
using namespace std;

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */

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

vector<vector<mi> > ID;


vector<vector<mi> > mult(vector<vector<mi> > & a, vector<vector<mi> > & b) {
	vector<vector<mi> > res(a.size(), vector<mi>(b[0].size(), 0));
	assert(b.size() == a[0].size());
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
	assert(v.size() == v[0].size());
	if (n == 0) {
    assert(ID.size() == v.size());
    return ID;
  }
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
	int tests;
	long long n, m, k;
	cin >> n >> m >> k;
	vector<vector<mi> > mat(n, vector<mi>(n, 0));

	ID = vector<vector<mi> >(n, vector<mi>(n, 0));
	for (int i = 0; i < n; i++) {
		ID[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) assert(ID[i][j] == 1);
			else assert(ID[i][j] == 0);
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		mat[x][y] += 1;
	}
	vector<vector<mi> > b(n, {0});
	b[0][0] = 1;
	for (int i = 1; i < n; i++) {
		assert(b[i][0] == 0);
	}
	auto x = mexp(mat, k);
	cout << x[0][n - 1].v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
