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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int m = s.length();
	vector<vector<mi> > dp(n + 1, vector<mi>(m, 0));
	dp[0][0] = 1;
	vector<vector<int> > t(m, vector<int>(26, 0));
	string x = "";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			x += (char)('A' + j);
			for (int l = 0; l < x.length(); l++) {
				if (x.substr(l) == s.substr(0, x.length() - l)) {
					t[i][j] = x.length() - l;
					break;
				}
			}
			x.pop_back();
		}
		x += s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			
			for (int k = 'a'; k <= 'z'; k++) {
				if (t[j][k - 'a'] != m) {
					dp[i][t[j][k - 'a']] += dp[i - 1][j];
				}
			}
		}
	}
	mi res = 1;
	for (int i = 1; i <= n; i++) {
		res *= 26;
	}
	for (int i = 0; i < m; i++) {
		res -= dp[n][i];
	}
	cout << res.v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
