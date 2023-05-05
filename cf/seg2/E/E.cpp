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


template <class T> 
struct Seg {
	int sz;
	vector<T> seg;
	const T ID = 0;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(const T & a, const T & b) {
		return a + b;
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l > tr || r < tl) return ID;
		if (l <= tl && r >= tr) {
			return seg[ind];
		}
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
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

	void upd(int ind, T val) {
		seg[ind + sz - 1] = val;
		pull((ind + sz - 2) / 2);
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	Seg<long long> add;

	add.init(n + 1);
	Seg<long long> sub;
	sub.init(n + 1);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, v;
			cin >> l >> r >> v;
			add.upd(l, add.query(l, l) + v);
			sub.upd(r, sub.query(r, r) + v);
		} else {
			int ind;
			cin >> ind;
			cout << add.query(0, ind)  - sub.query(0, ind) << endl;
		}
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
