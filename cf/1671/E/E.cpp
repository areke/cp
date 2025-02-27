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


int n;
string s;

pair<mi, string> solve(int x) {
	if (2 * x > n) return {1, s.substr(x - 1, 1)};
	auto left = solve(2 * x);
	auto right = solve(2 * x + 1);
	if (left.second == right.second) {
		return {left.first * right.first, s.substr(x - 1, 1) + left.second + right.second};
	} else {
		if (left.second > right.second) swap(left.second, right.second);
		return {2 * left.first * right.first, s.substr(x - 1, 1) + left.second + right.second};
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	n = 1 << n;
	n--;
	cin >> s;
	cout << solve(1).first.v << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
