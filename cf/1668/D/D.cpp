#include <bits/stdc++.h>
using namespace std;


template<class T> struct Seg {
	const T ID = -1e18;
	T comb(T a, T b) {
		return max(a, b);
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

	long long get(int ind) {
		return seg[n + ind];
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	T query(int l, int r) {
		if (r < l) return ID;
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
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + v[i];
		}
		Seg<long long> pos;
		Seg<long long> neg;
		pos.init(n + 1);
		neg.init(n + 1);
		map<long long, long long> c;
		set<long long> s;
		for (int i = 0; i < n + 1; i++) {
			s.insert(p[i]);
		}
		int cnt = 0;
		for (long long x : s) {
			c[x] = cnt++;
		}
		map<long long, long long> m;
		for (int i = 0; i <= n; i++) {
			pos.upd(i, -1e18);
		}
		for (int i = 0; i <= n; i++) {
			neg.upd(i, -1e18);
		}
		pos.upd(c[0], 0);
		neg.upd(c[0], 0);
		m[c[0]] = 0;
		vector<long long> dp(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int ind = c[p[i]];
			long long cur = -1e18;
			if (m.count(ind)) {
				cur = m[ind];
			}
			long long a = pos.query(0, ind - 1) + i;
			long long b = neg.query(ind + 1, n) - i;
			long long maxi = max(a, b);
			if (m.count(ind)) {
				//cout << "??" << endl;
				maxi = max(maxi, m[ind]);
			}
			dp[i] = maxi;
			pos.upd(ind, max(pos.get(ind), dp[i] - i));
			neg.upd(ind, max(neg.get(ind), dp[i] + i));
			m[ind] = max(cur, dp[i]);
			//cout << i << " " << ind << " " << maxi << " " << a << " " << b << endl;
		}
		cout << dp[n] << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
