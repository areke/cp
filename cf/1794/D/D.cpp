#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */
 
const long long MOD = 998244353;
 
struct mi { // WARNING: needs some adjustment to work with FFT
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
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
 
int MAXI = 1000000;
int MAXF = 1e4;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	vector<mi> fact(MAXF + 1, 0);
	fact[0] = 1;
	for (int i = 1; i <= MAXF; i++) {
		fact[i] =fact[i - 1] * i;
	}
	vector<mi> ifact(MAXF + 1, 0);
	ifact[0] = 1;
	for (int i = 1; i <= MAXF; i++) {
		ifact[i] = ifact[i - 1] / i;
	}
	vector<long long> b(MAXI + 1, 0);
	for (int i = 2; i <= MAXI; i++) {
		if (b[i]) continue;
		b[i] = 2;
		for (int j = 2 * i; j <= MAXI; j+= i) {
			b[j] = 1;
		}
	}
	set<long long> primes;
	for (int i = 2; i <= MAXI; i++) {
		if (b[i] == 2) {
			primes.insert(i);
		}
	}
 
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(2 * n);
		set<long long> s;
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
		}
 
		map<long long, long long> m;
		
		for (int i = 0; i < 2 * n; i++) {
			m[a[i]]++;
			if (primes.find(a[i]) != primes.end()) s.insert(a[i]);
		}
		
		vector<mi> dp(n + 1, 0);
		dp[0] = 1;
		vector<long long> v;
		vector<long long> c;
		for (auto it: m) {
			v.push_back(it.first);
			c.push_back(it.second);
		}
		long long tot = 0;
		// dp[i] = how many have i primes
		for (int i = 0; i < v.size(); i++) {	
			//cout << v[i] << " " << c[i] << endl;
			if (primes.find(v[i]) != primes.end()) {
				// number exponents total = tot + c[i] - j... tot - j before... c[i] new ones
				for (int j = min(n, i); j >= 0; j--) {
					if (tot - j >= 0) {
						//cout << j << " " <<dp[j].v<< " " << tot + c[i] - j << " " << tot - j << " " << c[i] << " " << (fact[tot + c[i] - j] / fact[tot - j] / fact[c[i]]).v << endl;
						if (j + 1 <= n) dp[j + 1] += dp[j] * fact[tot + (c[i] - 1) - j] * ifact[tot - j] * ifact[c[i] - 1];
						dp[j] *= fact[tot + c[i] - j] * ifact[tot - j] * ifact[c[i]];
					}
					
				}
			} else {	
				for (int j = 0; j <= min(n, i); j++) {
					if (tot - j >= 0) {
						//cout << j << " " <<dp[j].v<< " " << fact[tot + c[i]].v << " " << fact[tot - j].v << " " << fact[c[i]].v << endl;
						dp[j] *= fact[tot + c[i] - j] * ifact[tot - j] * ifact[c[i]];
					}
				}
			}
			tot += c[i];
		}
		cout << dp[n].v << endl;
 
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
