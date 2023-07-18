#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000;


template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = 1;
	int n;
	void init(int _n) {
		n = _n;
		sz = 1;
		while (sz <= _n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		if (a >= INF) return INF;
		if (b >= INF) return INF;
		long long l = lcm((long long)a, (long long)b);
    return l > INF ? INF : l;
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

	int find(int l, int r, int tl, int tr, int ind, int cur) {
		if (l <= tl && r >= tr) {
			bool good = cur % seg[ind] != 0;
			if (tl == tr && good) {
				//cout << tl << " " << tr << " " << cur << " " << seg[tl + sz - 1 ] << " k " << nxt << endl;
				return tl;
			}
			if (tl == tr || !good) return 1e9;
		}
		if (l > tr || r < tl) return 1e9;
		int left = find(l, r, tl, (tl + tr) / 2, 2 * ind + 1, cur);
		if (left < sz) return left;
		return find(l, r, (tl + tr ) / 2 + 1, tr, 2 * ind + 2, cur);
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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		Seg<int> seg;
		seg.init(n);
		for (int i = 0; i < n; i++) {
			seg.upd(i, a[i]);
		}
		int maxi = 2 * n + 1;
		vector<int> s(maxi + 1, 0);
		for (int i = 0; i < n; i++) {
			int l = a[i];
			int cur = i;
			while (l <= maxi) {
				if (cur > n - 1) break;
				s[l] = 1;
				if (cur == n - 1) break;
				//cout << i << " " << cur << " " << l << endl;
				int x = seg.find(cur + 1, n - 1, 0, seg.sz - 1, 0, l);
				int best = x;
				if (best < n) {
					l = slcm(a[best], l);
				}
				cur = best;
			}
		}
		int res = 0;
		for (int i = 1; i <= maxi; i++) {
			if (!s[i]) {
				res = i;
				break;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
