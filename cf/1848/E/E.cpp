#include <bits/stdc++.h>
using namespace std;


long long MOD = 1e9 + 7;

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


bool isPrime(long long x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

//returns list of prime factors with their counts
vector<pair<long long, long long> > factor(long long a) {
	vector<pair<long long, long long> > res;
	for (int j = 2; j <= sqrt(a); j++) {
		if (!isPrime(j)) continue;
		int cnt = 0;
		while (a % j == 0) {
			cnt ++;
			a /= j;
		}
		if (cnt) {
			res.push_back({j, cnt});
		}
	}
	if (a != 1) {
		res.push_back({a, 1});
	}
	return res;
}

long long MAXI = 1e6 + 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x, q;
	cin >> x >> q >> MOD;
	vector<map<long long, long long> > v(q);
	mi res = 1;
	auto f = factor(x);
	map<long long, long long> m;
	vector<map<long long, long long> > fact(MAXI + 1);
	for (int i = 2; i <= MAXI; i++) {
		if (!fact[i].empty()) continue;
		for (int j = i; j <= MAXI; j += i) {
			int x = j;
			while (x % i == 0) {
				fact[j][i]++;
				x /= i;
			}
		}
	}

	int zc = 0;
	for (auto it : f) {
		if (it.first == 2) continue;
		m[it.first] += it.second;
		if ((it.second + 1) % MOD == 0) zc++;
		else res *= (it.second + 1);
	}


	for (int i = 0; i < q; i++) {
		long long a;
		cin >> a;
		v[i] = fact[a];
	}
	for (auto a : v) {
		for (auto it : a) {
			if (it.first == 2) continue;
			if ((m[it.first] + 1) % MOD == 0) {
				zc--;
			} else {
				res = res / (m[it.first] + 1);
			}
			m[it.first] += it.second;
			if ((m[it.first] + 1) % MOD == 0) {
				zc++;
			} else {
				res *= (m[it.first] + 1);
			}
		}
		if (zc) cout << 0 << endl;
		else cout << res.v << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
