#include <bits/stdc++.h>
using namespace std;


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
	if (r > n) return 0;
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


mi res = 0;

int n, k;

mi dfs(int x, vector<vector<int> > & v, vector<int> & c, vector<mi> & d, int last = -1) {
	int res = 1;
	mi ret = 0;
	for (int n : v[x]) {
		if (n == last) continue;
		ret += dfs(n, v, c, d, x);
		res += c[n];
	}
	c[x] = res;
	d[x] = ret;
	ret += nCr(res, k);
	return ret;
}




void solve(int x, vector<vector<int> > & v, vector<int> & c, vector<mi> & d, int last = -1) {
//	if (last != -1) {
	//	d[x] = d[last] - nCr(c[x], k) + nCr(n - c[x], k);
	//}
	for (int nn : v[x]) {
		if (nn == last) continue;
		solve(nn, v, c, d, x);
		res -= nCr(c[nn], k) * (n - c[n]);
	}
	res -= nCr(n - c[x], k) * c[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prepareFact();
	cin >> n >> k;

	res = mi(n) * mi(n) * nCr(n, k);
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> c(n, 0);

	vector<mi> d(n, 0);
	dfs(0, v, c, d);
	for (int i = 0; i < n; i++) {
		//d[i] -= nCr(c[i], k);
	}
	//d[0] -= nCr(n, k);
	solve(0, v, c, d);
	for (int i = 0; i < n; i++) {
		//res -= d[i];
		cout << d[i].v << " ";
	}
	cout << res.v << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
