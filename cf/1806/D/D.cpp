#include <bits/stdc++.h>
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

const int MAXN = 500000 + 5;
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
	int tests = 0;
	cin >> tests;
	for (int test = 0; test < tests; test++) {



		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n - 1; i++) {
			cin >> v[i];
		}

		if (v[0] != 0) {
			for (int i = 0; i < n - 1; i++) {
				cout << 0 << " \n"[i == n - 2];
			}
			continue;
		}

		vector<mi> res(n - 1, 0);
		res[0] = 1;
		mi cur = 1;
		mi bad = 1;
		for (int i = 1; i < n - 1; i++) {
			cur *= (i + 1);
			if (v[i] == 0) {
				cur += bad * fact[i];
			} else {
				bad *= mi(i) / mi(i + 1);
			}
			res[i] = cur;
		}
		for (int i = 0; i < n - 1; i++) {
			cout << res[i].v << " \n"[i == n - 2];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
