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
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, x1, y1, x2, y2, p;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> p;
		set<array<int, 4> > vis;
		int dx = 1;
		int dy = 1;
		int res = 0;
		int s = 0;
		int c = 0;
		vector<int> v;
		while (true) {
			if (x1 + dx > n || x1 + dx < 1) {
				dx *= -1;
			} 
			if (y1 + dy > m || y1 + dy < 1) {
				dy *= -1;
			}
			if (vis.find({x1, y1, dx, dy}) != vis.end()) {
				break;
			}
			vis.insert({x1, y1, dx, dy});
			s++;
			
			if (x1 == x2 || y1 == y2) {
				v.push_back(res);
				c++;
			}
			
			x1 += dx;
			y1 += dy;
			res++;	
		}
		mi prob = mi(p) / 100;
		mi cp = 1;
		mi x = 0;
		for (int i = 0; i < v.size(); i++) {
			x += mi(v[i]) * prob * cp;
			cp *= (mi(1) - prob);
		}
		mi e =  (cp * s + x) / (mi(1) - cp);
		cout << e.v << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
