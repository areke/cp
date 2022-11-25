#include <iostream>
#include <string>
#include <assert.h>
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
 
 
const int MOD = 998244353;
 
 
 
struct mi {
 	int v; explicit operator int() const { return v; }
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
mi operator%(mi a, mi b) { return mi((long long) a.v % (long long) b.v); }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
 
mi gcd(mi a, mi b) {
	return a.v == 0 ? b : gcd(b % a, a);
}
 
int main() {
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	map<int, int> m;
	long long p = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> v[i][j];
			m[v[i][j]]++;
			p++;
		}
	}
	mi a1 = 0;
	mi b1 = 1; 
	mi nn = n;
	for (int i = 0; i < n; i++) {
		mi a2 = 0; 
		for (int j = 0; j < v[i].size(); j++) {
			a2 += m[v[i][j]];
		}
		mi b2 = nn * nn * v[i].size();
		a1 = a1 * b2 + b1 * a2;
		b1 = b1 * b2;
 
	}
	mi g = gcd(a1, b1);
	a1 = a1 / g;
	b1 = b1 / g;
	cout <<(int) (a1 * inv(b1)) << endl;
	return 0;
}

