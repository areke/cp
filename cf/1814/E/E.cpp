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

long long INF = 1e18;

struct node {
	long long m[2][2];
};

bool isID(node & n) {
	for (int i = 0; i< 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (n.m[i][j] != -1) return false;
		}
	}
	return true;
}

template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = {{{-1, -1}, {-1, -1}}};
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		if (isID(a)) return b;
		if (isID(b)) return a;
		node n = node();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				n.m[i][j] = INF;
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				n.m[i][j] = min(a.m[i][0] + b.m[1][j], a.m[i][1] + b.m[0][j]);
				n.m[i][j] = min(n.m[i][j], a.m[i][0] + b.m[0][j]);
			}
		}
    return n;
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

	T query(int l, int r) {
		return query(l, r, 0, sz - 1, 0);
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

	Seg<node> seg;
	seg.init(n - 1);
	
	for (int i = 0; i < n - 1; i++) {
		long long x;
		cin >> x;
		seg.upd(i, {{{x, INF}, {INF, 0}}});
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		long long x, y;
		cin >> x >> y;
		x--;
		seg.upd(x, {{{y, INF}, {INF, 0}}});
		cout << 2 * seg.query(0, n - 1, 0, seg.sz - 1, 0).m[0][0] << endl;

		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
