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


vector<vector<long long> > jmp(60, vector<long long>(3e5, 0));

vector<mi> solve(vector<mi> & b, long long k) {
	int n = b.size();
	if (k == 0) {
		vector<mi> ret(b.size(), 0);
		return ret;
	}
	auto next = [n](vector<long long> & a, vector<mi> & b) {
		vector<mi> cur(n, 0);
		for (int i = 0; i < n; i++) cur[a[i]] += b[i];
		return cur;
	};

	auto add = [n](vector<mi> & a, vector<mi> b) {
		for (int i = 0; i < n; i++) {
			a[i] += b[i];
		}
	};
	
	
	auto res = solve(b, k / 2);
	int ind = 0;

	vector<mi> nxt = res;
	for (int i = 0; i < 60; i++) {
		if (((k / 2) >> i) & 1) {
			nxt = next(jmp[i], nxt);
		}
	}
	add(res, nxt);

	if (k & 1) {
		auto nxt = next(jmp[0], res);
		add(nxt, b);
		if (k == 1) assert(nxt == b);
		return nxt;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long k;
	cin >> k;
	vector<long long> a(n);
	vector<mi> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		b[i] = x;
	}

	jmp[0] = a;

	for (int i = 1; i < 60; i++) {
		for (int j = 0; j < n; j++) {
			jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
		}
	}
	auto next = [n](vector<long long> & a, vector<mi> & b) {
		vector<mi> cur(n, 0);
		for (int i = 0; i < n; i++) cur[a[i]] += b[i];
		return cur;
	};

	auto add = [n](vector<mi> & a, vector<mi> b) {
		for (int i = 0; i < n; i++) {
			a[i] += b[i];
		}
	};
	b = next(jmp[0], b);

	vector<mi> c = solve(b, k);
	mi ki = mi(1) / mi(k);
	for (int i = 0; i < n; i++) {
		cout << (c[i] * ki).v << " \n"[i == n - 1];
	}

	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
