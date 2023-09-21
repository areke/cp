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

mi half = mi(1) / mi(2);

mi solve(int x, int y, vector<vector<mi> > & p, vector<vector<int> > & vis) {
	if (vis[x][y]) return p[x][y];
	vis[x][y] = 1;
	if (x <= y) return p[x][y] = 0;
	if (y == 0) return p[x][y] = x;
	return p[x][y] = half * (solve(x - 1, y, p, vis) + 1) + half * solve(x, y - 1, p, vis);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector vis(501, vector<int>(501, 0));
	vector<vector<mi> > p(501, vector<mi>(501, 0));
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			solve(i, j, p, vis);
		}
	}
	vector<int> v(m, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		v[x] = 1;
	}
	int first = -1;
	for (int i = m - 1; i >= 0; i--) {
		if (v[i]) {
			first = i;
			break;
		}
	}
	mi cur = m - first;
	int last = first;
	for (int i = first - 1; i >= 0; i--) {
		if (v[i]) {
			//cout << i << " " << last << " " << cur.v << endl;
		 	cur += p[m - i][m - last];
			//cout << m - i << " " << m - first << endl;
			last = i;
		}
	}
	cout << cur.v << endl;





	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
