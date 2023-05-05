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


template<class T> struct Seg {
	const T ID = {0, 0};
	T comb(T a, T b) {
		return max(a, b);
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

int luck(int n) {
	int maxi = -1;
	int mini = 1e7;
	while (n) {
		int d = n% 10;
		maxi = max(maxi, d);
		mini = min(mini, d);
		n /= 10;
	}
	return maxi - mini;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	Seg<pair<long long, long long> > seg;
	seg.init(1e6 + 1);
	for (int i = 1; i <= 1e6; i++) {
		seg.upd(i, {luck(i), i});
	}
	cin >> tests;
	while (tests--) {
		int l, r;
		cin >> l >> r;
		int res = seg.query(l, r).second;
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
