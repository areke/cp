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



struct node {
// MODIFY HERE
	long long v = 0;
	long long m = 0;
	node(long long v, long long m) {
		this->v = v;
		this->m = m;
	}
};


long long INF = 1e18;

template <class T>
struct LazySeg {
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
		return node(a.v + b.v, 0);
	}

	void push(int tl, int tr, int ind) {
		
		long long m = seg[ind].m;
		// MODIFY HERE
		if (m) {
			seg[ind].v = m * (tr - tl + 1);
		}
		seg[ind].m = 0;
		if (tl == tr) return;
		if (m) {
			seg[2 * ind + 1].m = m;
			seg[2 * ind + 2].m = m;
		}
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

	void set(int l, int r, long long v, int tl, int tr, int ind) {
		if (l > tr || r < tl) return;
		push(tl, tr, ind);
		if (l <= tl && r >= tr) {
			// MODIFY HERE
			seg[ind].m = v;
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
	int n, q;
	cin >> n >> q;
	Seg<long long> seg;
	LazySeg<node> seg2;
	seg.init(n);
	seg2.init(n);
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		seg.upd(i, v[i]);
		seg2.upd(i, {v[i], 0});
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
	vector<long long> res(q);
	for (int i = q - 1, ind = n - 1; i >= 0; i--) {
		while (ind >= queries[i][0]) {
			int low = ind + 1;
			int high = n - 1;
			int best = ind;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (seg2.query(mid, mid, 0, seg2.sz - 1, 0).v < v[ind]) {
					best = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			seg2.set(ind, best, v[ind], 0, seg2.sz - 1, 0);
			ind--;
		}
		res[queries[i][2]] = seg2.query(queries[i][0], queries[i][1], 0, seg2.sz - 1, 0).v;
		res[queries[i][2]] -= seg.query(queries[i][0], queries[i][1], 0, seg.sz - 1, 0);
	}
	for (int i = 0; i < q; i++) {
		cout << res[i] << "\n";
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
