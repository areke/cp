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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

long long MOD = 998244353;
struct mi {
 	long long v; explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a;
}
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }


mi nCr(long long n, long long r) {
	mi res = 1;
	for (long long p = n; p> n / 2; p--) {
		res =res * p;
	}
	for (long long p = 1; p <= n / 2; p++) {
		res = res / p;
	}
	return res;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		mi a[60];
		mi b[60];
		mi tot[60];
		for (int i = 1; i <= 30; i++) {
			tot[i] = nCr(2 *i, i);
		}
		a[1] = 1;
		b[1] = 0;
		for (int i = 2; i <= 30; i++) {
			a[i] = tot[i] / 2 + (tot[i - 1] - a[i - 1] - 1);
		}
		long long resa = a[n/2].v;
		long long resb = (tot[n / 2] - a[n / 2] - 1).v;
		cout << resa << " " << resb << " " << 1 << endl;

		
		}
	return 0;
}
