#include <bits/stdc++.h>
using namespace std;


vector<int> e(5e6 + 1, 0);

struct node {
	long long x, y, tl, tr;
};

template<class T> struct Seg {
	const T ID = {0, 0, 0, 0};
	T comb(T a, T b) {
		if (a.x == 0) return b;
		if (b.x == 0) return a;
		node res = {a.x, a.y + b.y, a.tl, b.tr};
		while (a.x != b.x) {
			if (a.x > b.x) {
				a.x = e[a.x];
				res.y += a.tr - a.tl + 1;
			} else {
				b.x = e[b.x];
				res.y += b.tr - b.tl + 1;
			}
		}
		res.x = a.x;
		return res;
	}
	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}
	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 5e6; i++) {
		e[i] = i;
	}
	for (int i = 2; i <= 5e6; i++) {
		if (e[i] == i) {
			for (int j = i; j <= 5e6; j+= i) {
				e[j] /= i;
				e[j] *= (i - 1);
			}
		}
	}

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (v[i] != 1) s.insert(i);
	}
	Seg<node> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		seg.upd(i, {v[i], 0, i, i});
	}

	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		l--;
		r--;
		if (t == 1) {
			for (auto it = s.lower_bound(l); it != s.end();) {
				if (*it > r) break;
				v[*it] = e[v[*it]];
				seg.upd(*it, {v[*it], 0, *it, *it});
				if (v[*it] == 1) {
					it = s.erase(it);
				} else {
					it++;
				}
			}
		} else {
			cout << seg.query(l, r).y << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
