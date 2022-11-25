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
#include <cstring>
using namespace std;


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

bool isPrime(long long x) {
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

long long count(vector<long long> & div, long long x) {
	long long res = 0;
	//cout << "----" << endl;
	for (int i = 1; i < (1 << div.size()); i++) {
		long long p = 1;
		int cnt = 0;
		for (int j = 0; j < div.size(); j++) {
			if ((1 << j) & i) {
				cnt++;
				p *= div[j];
			}
		}
		if (cnt % 2) {
			res += x / p;
		} else {
			res -= x / p;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		mi res = 1;
		vector<long long> primes;
		long long x = a[0];
		while (x > 1) {
			int found = -1;
			for (int i = 2; i <= sqrt(x); i++) {
				if (found != -1)break;
				if (isPrime(i)) {
					while (x % i == 0) {
						x /= i;
						found = i;
					}
				
				}
			}
			//cout << x << " " << found << endl;
			if (found != -1) primes.push_back(found);
			else {
				primes.push_back(x);
				break;
			}
		}
		for (int i = 1; i < n; i++) {
			if (a[i - 1] % a[i] != 0) {
				res = 0;
				break;
			}
			long long g = a[i - 1] / a[i];
			long long xx = m / a[i];
			vector<long long> div;
			for (int j = 0; j < primes.size(); j++) {
				if (g % primes[j] == 0) div.push_back(primes[j]);
			}
			long long bad = count(div, xx);

			//cout << "HUH " <<  i << " " << bad << " " << xx << " " << g << endl;
			res *= mi(xx - bad);
		}
		cout << res.v << endl;
	}
	return 0;
}
