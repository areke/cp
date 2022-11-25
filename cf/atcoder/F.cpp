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
#include <assert.h>
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


template<class T> struct Seg {
	const T ID = 0;
	T comb(T a, T b) {
		return a + b;
	}
	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}
    
	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

    T get(int ind) {
        return seg[n + ind];
    }

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxi = max(a[i], maxi);
    }
    Seg<long long> lower;
    lower.init(maxi + 1);
    Seg<long long> larger;
    larger.init(maxi + 1);
    

    // E(K) = E(k - 1) * (k - 1)^2 / k ^ 2 + (# smaller or equal to) / k * a[k] + (1 - (# smaller or equal to) / k) * (sum of larger / # of larger)
    vector<mi> res(n);
    res[0] = a[0];
    lower.upd(a[0], 1);
    larger.upd(a[0], a[0]);
    for (int i = 1; i < n; i++) {
        mi k = i + 1;
        mi frac = mi(k - 1) * mi(k - 1) / k / k;
        lower.upd(a[i], lower.get(a[i]) + 1);
        larger.upd(a[i], larger.get(a[i]) + a[i]);
        long long numlower = lower.query(0, a[i]);
        long long sumlarger = larger.query(a[i] + 1, maxi);
        res[i] = res[i - 1] * frac;
        res[i] += mi(2) * mi(numlower) / k / k * mi(a[i]);
        res[i] -= mi(1) / k / k * mi(a[i]);
        if (k.v != numlower) {
            res[i] += 2 * (k - mi(numlower)) / k /k * sumlarger / (k - mi(numlower));
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i].v << endl;
    }
}