#include <bits/stdc++.h>
using namespace std;


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
    return a + b;
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
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<array<int, 3> > queries;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		queries.push_back({l, r, i});
	}
	sort(queries.begin(), queries.end());
	Seg<int> seg;
	seg.init(n);
	map<int, int> m;
	vector<int> res(q);
	for (int i = q - 1, ind = n - 1; i >= 0; i--) {
		while (ind >= queries[i][0]) {
			if (m.count(v[ind])) {
				seg.upd(m[v[ind]], 0);
			}
			m[v[ind]] = ind;
			seg.upd(ind, 1);
			ind--;
		}
		res[queries[i][2]] = seg.query(queries[i][0], queries[i][1]);
	}
	for (int i = 0; i < q; i++) {
		cout << res[i] << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
