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
	T ID = 0;
	vector<T> seg;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		return a + b;
	}


	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) return seg[ind];
		if (l > tr || r < tl) return ID;
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		return comb(left, right);
	}

	int findK(int k, int tl, int tr, int ind) {
		if (k == 1 && seg[ind] == 1 && tr - tl + 1 == 1) {
			return tl;
		}
		int left = seg[2 * ind + 1];
		int right = seg[2 * ind + 2];
		if (k <= left) {
			return findK(k, tl, (tl + tr) / 2, 2 * ind + 1);
		} else {
			return findK(k - left, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		}
	}


	void pull(int ind) {
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
		if (ind == 0) return;
		pull((ind - 1) / 2);
	}

	T get(int ind) {
		return seg[ind + sz - 1];
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
	Seg<long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		seg.upd(i, x);
	}
	for (int i = 0; i < m; i++) {
		int t, x;	
		cin >> t >> x;
		if (t == 1) {
			seg.upd(x, seg.get(x) ^ 1);
		} else {
			cout << seg.findK(x + 1, 0, seg.sz - 1, 0) << endl;
		}
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
