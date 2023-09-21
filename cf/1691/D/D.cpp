#include <bits/stdc++.h>
using namespace std;


template<class T> struct Seg {
	const T ID = 1e18;
	T comb(T a, T b) {
		return min(a, b);
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

bool solve(vector<long long> & v, int n) {
	vector<long long> p(n + 1, 0);
		vector<int> g(n, -1);
		stack<int> s;
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && v[s.top()] < v[i]) {
				g[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + v[i];
		}
		Seg<long long> seg;
		seg.init(n + 1);
		for (int i = 0; i <= n; i++) {
			seg.upd(i, p[i]);
		}
		long long val = -1e18;
		for (int i = 1; i < n; i++) {
			int l = g[i] + 1;
			long long b = (p[i + 1] - seg.query(l, i)) - v[i];
			val = max(val, b);
		}
		return val <= 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		bool can = true;
		can &= solve(v, n);
		reverse(v.begin(), v.end());
		can &= solve(v, n);
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
