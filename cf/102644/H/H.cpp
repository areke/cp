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
 
vector<vector<mi> > mult(const vector<vector<mi> > & a, const vector<vector<mi> > & b) {
	vector<vector<mi> > res(a.size(), vector<mi>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			for (int k = 0; k < b[0].size(); k++) {
				res[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	return res;
}
 
const vector<vector<mi> > happy = {{1, 1}, {0, 0}};
const vector<vector<mi> > sad = {{0, 0}, {1, 1}};
const vector<vector<mi> > flip = {{0, 1}, {1, 0}};
const vector<vector<mi> > nothing = {{1, 0}, {0, 1}};
const vector<vector<mi> > q = {{19, 6}, {7, 20}};
 
 
template<class T> struct Seg {
	const vector<vector<mi> > ID = nothing;
	T comb(T a, T b) {
		return mult(a, b);
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
 
 
 
 
void upd(int i, char c, Seg<vector<vector<mi> > > & seg) {
	if (c == 'S' || c == 'D') {
		seg.upd(i, sad);
	} else if (c == 'H') {
		seg.upd(i, happy);
	} else if (c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U') {
		seg.upd(i, flip);
	} else if (c == '?') {
		seg.upd(i, q);
	} else {
		seg.upd(i, nothing);
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, qq;
	cin >> n >> qq;
	string s;
	cin >> s;
	vector<pair<int, char> > queries(qq);
	for (int i = 0; i < qq; i++) {
		cin >> queries[i].first >> queries[i].second;
	}
	Seg<vector<vector<mi> > > seg;
	seg.init(n);
 
	
 
	for (int i = 0; i < n; i++) {
		upd(n - i - 1, s[i], seg);
	}
	vector<vector<mi> > cur = {{1}, {0}};
	vector<vector<mi> > t = seg.query(0, n - 1);
	cout << mult(t, cur)[0][0].v << endl;
	vector<long long> res(qq);
	for (int i = 0; i < qq; i++) {
		int ind = queries[i].first;
		char c = queries[i].second;
		ind--;
		upd(n - ind - 1, c, seg);
		vector<vector<mi> > t = seg.query(0, n - 1);
		res[i] =  mult(t, cur)[0][0].v;
	}
	for (int i = 0; i < qq; i++) {
		cout << res[i] << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}