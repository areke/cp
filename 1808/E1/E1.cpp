#include <bits/stdc++.h>
using namespace std;


long long MOD;

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


mi dp(long long i, long long j, long long b) {
	if (i == 0) {
		if (j == 0) return 1;
		return 0;
	}
	return modExp(b, i - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, b;
	cin >> n >> b >> MOD;

	prepareFact();
	mi tot = 0;
	vector<mi> res(b, 0);
	mi mult = 1;
	// nCr(n, i) * b^{n - i} = 
	// (1 - b)^n
	
	for (int i = n; i <= n; i++) {
		for (int j = 0; j < b; j++) {
			long long s = (j * (i - 1)) % b;
			// x + s == j % b
			// x + j * (n - 1) == j % b
			// -x = (n - 2) * j
			// x == j - s
			// 
			
			// j + b - s
			// - j * (n - 2) == x
			// j * (n - 2) == 0
			//res[j] += nCr(n, i) * dp(n - i, (j + b - s) % b, b) * mult;
//			cout << i << " " << j << " " << res[j].v << endl;
			if (n == i && (j + b - s) % b) {
				cout << j << endl;
			}
			//cout << i << " " << j << " " << (nCr(n, i) * dp[n - i][(j + b - s) % b] * mult).v << " " << dp[n - i][(j + b - s) % b].v << endl;
		}
		mult *= -1;
	}
	
	for (int j = 0; j < n; j++) {
		res[j] -= modExp(b - 1, n) / b;
		res[j] += modExp(-1, n) / b;
		res[j] += modExp(b, n - 1);
	}
	for (int j = 0; j < n; j++) {
		if ((j * (n - 2)) % b == 0) {
			res[j] += modExp(-1, n - 1);
			cout << j << endl;
		}
	}

	mi ans = 0;
	for (int i = 0; i < b; i++) {
		ans += res[i];
	}
	if (b % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + i <= n; j++) {
				for (int k = 0; k < b / 2; k++) {
					mi mult = 1;
					if ((i + j) % 2 == 0) mult = -1;
					long long s = ((i - 1) * k + j * (k + b / 2)) % b;
					long long t = (i * k + (j - 1) * (k + b / 2)) % b;
					long long ks = (k - s + b) % b;
					long long ts = (k + b / 2 - t + b) % b;
					assert(ks == ts);
					ans += nCr(n, i) * nCr(n - i, j) * dp(n - i - j, ks, b) * mult;
				}
			}
		}
	}
	cout << ans.v << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
