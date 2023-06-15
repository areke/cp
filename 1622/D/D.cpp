#include <bits/stdc++.h>
using namespace std;
 
/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */
 
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
 
const int MAXN = 200000 + 5;
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
 
mi modExp(mi a, long long b) {
	if (b == 0) return 1;
	mi res = modExp(a, b / 2);
	res *= res;
	if (b % 2) res *= a;
	return res;
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prepareFact();
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<vector<int> > v;
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}
	vector<int> inds;
	int st = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') inds.push_back(i);
	}
	for (int i = k - 1; i < inds.size(); i++) {
		if (i + 1 < inds.size()) {
			v.push_back({st, inds[i + 1] - 1});
		} else {
			v.push_back({st, n - 1});
		}
		st = inds[i - (k - 1)] + 1;
	}
	mi res = 1;
	if (v.empty()) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		res += nCr(v[i][1] - v[i][0] + 1, k);
		if (i > 0 && v[i][0] <= v[i - 1][1]) {
			res -= nCr(v[i - 1][1] - v[i][0] + 1, k - 1);
		} else {
			res -= 1;
		}
	}
	cout << res.v << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}