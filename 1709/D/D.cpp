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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


template<class T> struct Seg {
	const T ID = 0;
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<long long> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	Seg<long long> seg;
	seg.init(m);
	for (int i = 0; i < m; i++) {
		seg.upd(i, v[i]);
	}

	int q;
	cin >> q;
	for (int qq = 0; qq < q; qq++) {
		int xs, ys, xf, yf;
		cin >> xs >> ys >> xf >> yf;
		int k;
		cin >> k;
		if ((xs % k != xf % k) ||  (ys % k  != yf % k)) {
			cout << "NO" << endl;
			continue;
		}
		int maxi = n / k * k + (xs % k);
		if (maxi > n) maxi -= k;
		if (ys > yf) swap(ys, yf);
		if (seg.query(ys - 1, yf - 1) >= maxi) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;

		}



	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
