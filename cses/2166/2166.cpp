#include <bits/stdc++.h>
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
	const T ID = node(-1e18, 0);
	
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		// MODIFY HERE
		return node(max(a.v + a.m, b.v + b.m), 0);
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
	int tests;
	int n, q;
	cin >> n >> q;
	Seg<node> seg;
	vector<long long> v(n);
	vector<long long> p(n + 1, 0);
	seg.init(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + v[i];
	}
	for (int i = 0; i <= n; i++) {
		seg.upd(i, {p[i], 0});
	}
	for (int i = 0; i < q; i++) {
		long long t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			long long dif = b - v[a - 1];
			v[a - 1] = b;
			seg.add(a, n, dif, 0, seg.sz - 1, 0);
		} else {
			cout << max(0LL, seg.query(a, b, 0, seg.sz - 1, 0).v  - seg.query(a - 1, a-1, 0, seg.sz - 1, 0).v) << endl;
		}
		
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
