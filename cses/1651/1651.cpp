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
// MODIFY HERE
	long long v = 0;
	long long m = 0;
	node(long long v, long long m) {
		this->v = v;
		this->m = m;
	}
};


long long MOD = 1e9 + 7;
long long INF = 1e18;

template <class T>
struct Seg {
	vector<T> seg;
	int sz;
	// MODIFY HERE
	const T ID = node(0, 0);
	
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		// MODIFY HERE
		return node(a.v + b.v + a.m + b.m, 0);
	}

	void push(int tl, int tr, int ind) {
		
		long long m = seg[ind].m;
		// MODIFY HERE
		seg[ind].v += m;
		seg[ind].m = 0;
		if (tl == tr) return;
		seg[2 * ind + 1].m += m;
		
		seg[2 * ind + 2].m += m;
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l > tr || r < tl) return ID;
		push(tl, tr, ind);
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

	void upd(int ind, T val) {
		seg[ind + sz - 1] = val;
		pull((ind + sz - 2) / 2);
	}

	void add(int l, int r, long long v, int tl, int tr, int ind) {
		if (l > tr || r < tl) return;
		push(tl, tr, ind);
		if (l <= tl && r >= tr) {
			// MODIFY HERE
			seg[ind].m += v;
			return;
		} 
		add(l, r, v, tl, (tl + tr) / 2, 2 * ind + 1);
		add(l, r, v, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
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
		seg.upd(i, {x, 0});
	}
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t;
		if (t == 2) {
			cin >> l;
			l--;
			node nd = seg.query(l, l, 0, seg.sz - 1, 0);
			cout << nd.v << endl;
		} else {
			long long v;
			cin >> l >> r >> v;
			l--;
			r--;
			seg.add(l, r, v, 0, seg.sz - 1, 0);
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
