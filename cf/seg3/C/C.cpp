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

struct node {
	vector<long long> v;
	long long inv = 0;
	node(int x) {
		v.assign(41, 0);
		if (x != 0) v[x] = 1;
		inv = 0;
	}
	node(vector<long long> x, long long y) {
		v = x;
		inv = y;
	}
};

template <class T>
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = node(0);
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(const T & a, const T & b) {
		vector<long long> v(41, 0);
		for (int i = 0; i < 41; i++) {
			v[i] = a.v[i] + b.v[i];
		}
		long long s = 0;
		long long inv = 0;
		for (int i = 40; i >= 0; i--) {
			inv += s * b.v[i];
			s += a.v[i];
		}
			return node(v, inv + a.inv + b.inv);
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l > tr || r < tl) return ID;
		if (l <= tl && r >= tr) return seg[ind];
		
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		
		return comb(left, right);
	}

	void pull(int ind) {
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
		if (ind == 0) return;
		pull((ind - 1) / 2);
	}

	void upd(int ind, T v) {
		seg[ind + sz - 1] = v;
		pull((ind + sz - 2) / 2);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	Seg<node> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		seg.upd(i, node(x));
	}

	for (int i = 0; i < q; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			x--;
			y--;
			cout << seg.query(x, y, 0, seg.sz - 1, 0).inv << "\n";
		} else {
			seg.upd(x - 1, node(y));
		}
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
