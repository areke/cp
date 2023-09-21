#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

struct node {
	long long v[31];
	node() {
		for (int i = 0; i < 31; i++) {
			v[i] = INF;
		}
	}
	node(long long x) {
		for (int i = 0; i < 31; i++) {
			v[i] = INF;
		}
		v[0] = x;
	}
};


template<class T> struct Seg {
	const T ID = {};
	T comb(T a, T b) {
		node ret;
		int x = 0, y = 0;
		for (int i = 0; i < 31; i++) {
			if (a.v[x] < b.v[y]) {
				ret.v[i] = a.v[x++];
			} else {
				ret.v[i] = b.v[y++];
			}
		}
		return ret;
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
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		Seg<node> seg;
		
		int n;
		cin >> n;
		seg.init(n);
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n; i++) {
			seg.upd(i, {v[i]});
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			auto s = seg.query(l, r);
			long long best = 1e18;
			for (int i = 0; i < 31; i++) {
				for (int j = i + 1; j < 31; j++) {
					best = min(best, s.v[i] | s.v[j]);
				}
			}
			cout << best << "\n";
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
