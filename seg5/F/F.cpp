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

const long long BAD = -1e18 - 12345;

struct node {
	// MODIFY HERE
	long long v = 0;
	long long m = 0;
	long long s = BAD;
	node(long long v, long long m, long long s) {
		this->v = v;
		this->m = m;
		this->s = s;
	}
};


template <class T>
struct Seg {
	vector<T> seg;
	int sz;
	// MODIFY HERE
	const T ID = node(0, 0, BAD);
	
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		// MODIFY HERE
		return node(a.v + b.v, 0, BAD);
	}

	void push(int tl, int tr, int ind) {
		if (ind >= seg.size()) return;
		long long s = seg[ind].s;
		long long m = seg[ind].m;
		// MODIFY HERE REMEMBER SUM NEEDS * (tr - tl + 1)
		if (s != BAD) {
			seg[ind].v = s * (tr - tl + 1);
			seg[ind].s = BAD;
		}
		seg[ind].v += m * (tr - tl + 1);
		seg[ind].m = 0;
		if (tl == tr) return;

		if (s != BAD) {
			seg[2 * ind + 1].s = s;
			seg[2 * ind + 2].s = s;
		}
		seg[2 * ind + 1].m += m;
		seg[2 * ind + 2].m += m;
	}

	T query(int l, int r, int tl, int tr, int ind) {
		push(tl, tr, ind);
		if (l > tr || r < tl) return ID;
		if (l <= tl && r >= tr) return seg[ind];
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
		return comb(left, right);
	}
	void add(int l, int r, long long v, int tl, int tr, int ind) {
		push(tl, tr, ind);
		if (l > tr || r < tl) return;
		if (l <= tl && r >= tr) {
			// MODIFY HERE
			seg[ind].m += v;
			push(tl, tr, ind);
			return;
		} 
		add(l, r, v, tl, (tl + tr) / 2, 2 * ind + 1);
		add(l, r, v, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	void set(int l, int r, long long v, int tl, int tr, int ind) {
		push(tl, tr, ind);
		if (l > tr || r < tl) return;
		if (l <= tl && r >= tr) {
			// MODIFY HERE
			seg[ind].s = v;
			seg[ind].m = 0;
			push(tl, tr, ind);
			return;
		} 
		set(l, r, v, tl, (tl + tr) / 2, 2 * ind + 1);
		set(l, r, v, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
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
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		r--;
		if (t == 1) {
			long long v;
			cin >> v;
			seg.set(l, r, v, 0, seg.sz - 1, 0);
		} else {
			cout << seg.query(l, r, 0, seg.sz - 1, 0).v << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
