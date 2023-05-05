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

const long long INF = 1e18;

vector<long long> lv, rv;

struct node {
	long long l, r;
	vector<long long> ld(2);
	vector<long long> rd(2);
	long long v = 0;

	node(long long a, long long b, vector<long long> & c, vector<long long> & d, long long v) {
		l = a;
		r = b;
		ld = c;
		rd = d;
		this->v = v;
	}

}

template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = 0;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		
		long long v = min(a.rd[1] + rv[a.tr] + b.rd[1], a.rd[0] + b.rd[0]);
		vector<long long> ld, rd;
		ld = a.ld;
		rd = b.rd;
		if (a.l == a.r || b.l == b.r) {
			v = a.rd[1] + rv[a.tr] + b.rd[1];
			ld = {v, 1e18};
			rd = {v, 1e18};
		} else {

		}
		
		long long l = a.l;
		long long r = a.r;
		return node(l, r, ld, rd, v);
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) {
			return seg[ind];
		}
		if (l > tr || r < tl) return ID;
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr ) / 2 + 1, tr, 2 * ind + 2);
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
	int n;
	cin >> n;
	lv.assign(n, 1e18);
	rv.assign(n, 1e18);
	
	for (int i = 0; i < n - 1; i++) {
		long long x;
		cin >> x;
		lv[i + 1] = x;
		rv[i] = x;
	}

	Seg<node> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		seg.upd(i, node(i, i, {1e18, 0}, {1e18, 0}));
	}
	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		long long x, y;
		cin >> x >> y;
		x--;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
