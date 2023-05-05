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
	long long v = 0;
	long long a = 0;
	node(long long v, long long a) {
		this->v = v;
		this->a = a;
	}
};
 
template <class T>
struct Seg {
	vector<T> seg;
	int sz;
	T ID = node(0, 0);
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}
 
	T comb(T a, T b) {
		return node(max(a.v, b.v), 0);
	}
 
	void push(int ind, long long tl, long long tr) {
		seg[ind].v = max(seg[ind].v, seg[ind].a);
		long long a = seg[ind].a;
		seg[ind].a = 0;
		if (tl == tr) return;
		seg[2 * ind + 1].a = max(seg[2 * ind + 1].a, a);
		seg[2 * ind + 2].a = max(seg[2 * ind + 2].a, a);
	}
 
	void add(int l, int r, long long v, int tl, int tr, int ind) {
		if (l > tr || r < tl) return;
		if (l <= tl && r >= tr) {

				seg[ind].a = max(seg[ind].a, v);

				return;
		}
		add(l, r, v, tl, (tl + tr) / 2, 2 * ind + 1);
		add(l, r, v, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
	}
 
	T query(int l, int r, int tl, int tr, int ind) {
		if (l > tr || r < tl) return ID;
		push(ind, tl, tr);
		if (l <= tl && r >= tr) return seg[ind];
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		return comb(left, right);
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
		int t;
		cin >> t;
		if (t == 1) {
			long long l, r, v;
			cin >> l >> r >> v;
			r--;
			seg.add(l, r, v, 0, seg.sz - 1, 0);
		} else {
			int l;
			cin >> l;
			cout << seg.query(l, l, 0, seg.sz - 1, 0).v << endl;
		}
	}
 
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
