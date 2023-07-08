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


const long long B = 31;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		string s, t;
		cin >> n >> m;
		cin >> s >> t;

		bool can = true;
		vector<int> l(n, 0);
		vector<int> r(n, 0);
		vector<mi> hs(n + 1, 0);
		vector<mi> ht(m + 1, 0);
		vector<mi> pb(n + 1, 0);
		pb[0] = 1;
		for (int i = 1; i <= n; i++) {
			pb[i] = pb[i - 1] * B;
		}
		long long b = 1;
		for (int i = 0; i < n; i++) {
			hs[i + 1] = hs[i]+ (s[i] - 'a' + 1) * b;  
			b *= B;
			b %= MOD; 
		}
		b = 1;
		for (int i = 0; i < m; i++) {
			ht[i + 1] = ht[i] + (t[i] - 'a' + 1) * b;
			b *= B;
			b %= MOD;
		}
		for (int i = 0, j = 0; i < m; i++) {
			while (j < n && s[j] != t[i]) {
				l[j] = i;
				j++;
			}
			if (j >= n) {
				can = false;
				break;
			}
			l[j] = i + 1;
			j++;
		}
		for (int i = 1; i < n; i++) {
			l[i] = max(l[i], l[i - 1]);
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 0, j = 0; i < m; i++) {
			while (j < n && s[n - j - 1] != t[m - i - 1]) {
				r[n - j - 1] = i;
				j++;
			}
			r[n - j - 1] = i + 1;
			j++;
		}
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i], r[i + 1]);
		}
		int res = n;
		int back = n - m;
		for (int i = n; i > 0; i--) {
			int left = l[i - 1];
			int right = i < n ? r[i] : 0;
			for (int j = 0; j <= right; j++) {
				if (j + left < m) continue;
				int best = 0;
				int low = 0;
				int high = min(i, m - j);
				//cout << i << " " << j << " " << low << " " << high << endl;
				while (low <= high) {
					int mid = (low + high) / 2;
					mi shash, thash;
					
					if (i - mid > m - j - mid) {
						shash = (hs[i - mid] - hs[i]);
						thash = (ht[m - j - mid] - ht[m - j]) * pb[i - mid - (m - j - mid)];
					} else {
						shash = (hs[i - mid] - hs[i]) * pb[(m - j - mid) - (i - mid)];
						thash = (ht[m - j - mid] - ht[m - j]);
					}
					
					//cout << shash.v << " " << thash.v << endl;
					if (shash == thash) {
						best = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
				//cout << i << " " << j << " " << best << endl;
				int num = i - best;
				if (num) {
					res = min(res, n - m + j + num + 1);
				} else {
					res = min(res, n - m + j);
				}
			}
		}
		cout << res << endl;

		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
