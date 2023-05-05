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



const long long MOD = 4294967296;

struct mi { // WARNING: needs some adjustment to work with FFT
 	unsigned int v; explicit operator int() const { return v; } 
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
mi operator*(mi a, mi b) { return mi((unsigned int)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, unsigned int p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

vector<vector<mi> > mult(vector<vector<mi> > & a, vector<vector<mi> > & b) {
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

vector<vector<mi> > add(vector<vector<mi> > a, vector<vector<mi> > b) {
	vector<vector<mi> > res(a.size(), vector<mi>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			res[i][j] = a[i][j] + b[i][j];
		}
	}
	return res;
}

vector<vector<mi> > subtract(vector<vector<mi> > a, vector<vector<mi> > b) {
	vector<vector<mi> > res(a.size(), vector<mi>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			res[i][j] = a[i][j] - b[i][j];
		}
	}
	return res;
}

void copy(vector<vector<mi> > a, vector<vector<mi> > & b) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			b[i][j] = a[i][j];
		}
	}
}

vector<vector<mi> > mexp(vector<vector<mi> > & v, vector<vector<mi> > & tot, long long n) {
	if (n == 0){
		tot[0][0] += 1;
		return {{1, 0}, {0, 1}};
		
	}
	if (n == 1) {
		vector<vector<mi> > first(64, vector<mi>(1, 0));
		first[0][0] = 1;
		copy(mult(v, first), tot);
		tot[0][0] += 1;
		return v;
	}
	vector<vector<mi> > f1(64, vector<mi>(1, 0));
	f1[0][0] = 1;
	vector<vector<mi> > res(v.size(), vector<mi>(v[0].size()));
	vector<vector<mi> > cur(64, vector<mi>(1, 0));
	res = mexp(v, cur, n / 2);
	cur = add(mult(res, cur), cur);
	cur = subtract(cur, mult(res, f1));
	res = mult(res, res);
	if (n % 2) {
		res = mult(res, v);
		cur = mult(v, cur);
		vector<vector<mi> > first(64, vector<mi>(1, 0));
		first[0][0] = 1;
		cur = add(cur, first);
	}
	copy(cur, tot);
	return res;
}

int h (int x, int y) {
	return 8 * x + y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<mi> > v(64, vector<mi>(64, 0));
	vector<vector<int> > moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (auto & m : moves) {
				if (m[0] + i < 0 || m[0] + i >= 8) continue;
				if (m[1] + j < 0 || m[1] + j >= 8) continue;
				int c = h(i, j);
				int d = h(m[0] + i, m[1] + j);
				v[c][d] = 1;
			}
		}
	}
	vector<vector<mi> > first(64, vector<mi>(1, 0));
	vector<vector<mi> > tot(64, vector<mi>(1, 0));
	first[0][0] = 1;
	mi res = 0;
	auto mid = mexp(v, tot, n);
	for (int i = 0; i < 64; i++) {
			res += tot[i][0];
	}
	cout << res.v << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
