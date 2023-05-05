#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <unordered_map>
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
 
 

unordered_map<long long, mi> cm;

unordered_map<long long, mi> fm;

mi c(long long x) {
    if (x == 0) return 1;
    if (x == 1) return 1;
		if (cm.count(x)) return cm[x];
    if (x % 2 == 0) return cm[x] = c(x / 2) + c(x/ 2 - 1);
    else {
        return cm[x] = c(x / 2);
    }
}
 
mi f(long long x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
		if (fm.count(x)) return fm[x];
    if (x % 2 == 0) {
        return fm[x] = 2 * (f(x / 2) + f(x / 2 - 1));
    } else {
        return fm[x] = 2 * f(x / 2) + c(x / 2);
    }
 
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    while (tests--) {
        long long n, m;
        cin >> n >> m;
        if (m == 1) {
            cout << n % MOD << endl;
        } else if (m == 2) {
            cout << f(n).v << endl;
        } else {
            mi res = mi(n / 2  + n % 2) * mi(n / 2 + 1);
            cout << res.v << endl;
        }
    }
 
    // IF STUCK:
        // DIV CONQUER?
        // CONSIDER SMALL CASES
    return 0;
}