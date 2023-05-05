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
	long long m, t, l, r;
	node(long long a, long long b, long long c, long long d) {
		m = max(0LL, a);
		t = b;
		l = max(0LL, c);
		r = max(0LL, d);
	}
};

template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = node(0, 0, 0, 0);
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		long long left = max(a.l, b.l + a.t);
		long long right = max(b.r, a.r + b.t);
		long long tot = a.t + b.t;
		long long maxi = max(a.m, b.m);
		maxi = max(maxi, a.r + b.l);
		return node(maxi, tot, left, right);
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) {
			return seg[ind];
		}
		if (l > tr || r < tl) return ID;
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
	int n, m;
	cin >> n >> m;
	Seg<node> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		seg.upd(i, node(x, x, x, x));
	}
	cout << seg.query(0, n - 1, 0, seg.sz - 1, 0).m << endl;
	for (int i = 0; i < m; i++) {
		int ind, v;
		cin >> ind >> v;
		seg.upd(ind, node(v, v, v, v));
		cout << seg.query(0, n - 1, 0, seg.sz - 1, 0).m << endl;
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
