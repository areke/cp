#include <bits/stdc++.h>
using namespace std;


template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = 1e18;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
    return min(a,b);
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
	int tests;
	int n, q;
	cin >> n >> q;
	Seg<long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		seg.upd(i, x);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		int t;
		cin >> t >> l >> r;
		if (t == 1) {
			l--;
			seg.upd(l, r);

		} else {
			l--;
			r--;
			cout << seg.query(l, r) << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
