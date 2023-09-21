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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prepareFact();
	int n;
	cin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	vector<set<int> > s(n);
	for (int i = 0; i < n; i++) {
		map<int, vector<int> > d;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
			d[dist].push_back(j);
		}
		for (auto it : d) {
			for (int j : it.second) {
				s[i].insert(j);
			}
			s[i].insert(i);
			break;
		}
	}

	set<set<int> > cand;
	for (int i = 0; i < n; i++) {
		bool can = true;
		for (int j : s[i]) {
			if (s[j] != s[i]) can = false;
		}
		if (can) cand.insert(s[i]);
	}
	int two = 0;
	int three = 0;
	int four = 0;
	for (auto it : cand) {
		if (it.size() == 2) two++;
		else if (it.size() == 3) three++;
		else if (it.size() == 4) four++;
	}
	mi res = 0;
	for (int i = 0; i <= two; i++) {
		for (int j = 0; j <= three; j++) {
			for (int k = 0; k <= four; k++) {
				int col = n - i - 2 * j - 3 * k;
				//cout << i << " " << j << " " << (nCr(four, k) * nCr(two, i) * nCr(three, j) * fact[col] * nCr(n, col)).v << " " << col << endl;
				res += nCr(four, k) * nCr(two, i) * nCr(three, j) * fact[col] * nCr(n, col);
			}
		}
	}
	cout << res.v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
