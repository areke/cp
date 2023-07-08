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

const int MAXN = (1 << 19) + 5;
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

int main() {
	// test
	prepareFact();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	if (k == 0) {
		int x;
		cin >> x;
		cout << 1 << endl;
		return 0 ;
	}
	map<int, int> m;
	int n = (1 << k);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x] = i;
	}
	vector<mi> twos(MAXN, 0);
	twos[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		twos[i] = twos[i - 1] * 2;
	}
	int last = 0;
	int round = 2;
	for (int i = 1; i <= k; i++) {
		set<int> s;
		int used = 0;

		round = (1 << i);
		for (int j = 1; j <= round; j++) {
			if (m.count(j)) {
				used++;
				s.insert(m[j] / (1 << (k - i)));
			}
		}
		if (s.size() != used) {
			cout << 0  << endl;
			return 0;
		}
		s.clear();
		used = 0;
		for (int j = round + 1; j <= 2 * round; j++) {
			if (m.count(j)) {
				used++;
				s.insert(m[j] / (1 << (k - i)));
			}
		}
		if (s.size() != used) {
			cout << 0 << endl;
			return 0;
		}
	}
	last = 0;
	mi res = 1;
	for (int i = 1; i <= k; i++) {
		int used = 0;
		for (int j = last + 1; j <= (1 << i); j++) {
			if (m.count(j)) {
				used++;
			}
		}
		set<int> s;
		int tused = 0;
		for (int j = 1; j <= (1 << i); j++) {
			if (m.count(j)) {
				s.insert(m[j] / (1 << (k - i + 1)));
			}
		}
		tused = s.size();
		if (i == 1) {
			used = min(used, 1);
			tused = min(tused, 1);
		}
		res *= fact[twos[i - 1].v - used];
		res *= twos[twos[i - 1].v];
		res = res / twos[tused];
		last = (1 << i);
	}
	cout << res.v << endl;


	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
