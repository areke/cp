#include <bits/stdc++.h>
using namespace std;


template<class T> struct Seg {
	const T ID = 0;
	T comb(T a, T b) {
		return a + b;
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
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		vector<long long> f(n + 1, -1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<pair<long long, long long> > v(n); 
		for (int i = 0; i < n; i++) {
			v[i] = {a[i], b[i]};
		}
		
		sort(v.begin(), v.end());
		for (int i = n - 1; i >= 0; i--) {
			f[v[i].first] = i;
		}
		long long res = 0;
		for (long long j = 1; j * j <= 2 * n; j++) {
			if (f[j] == -1) continue; 
			vector<int> m(n + 1, 0);
			for (int i = f[j]; i < n; i++) {
				long long t = j * v[i].first - v[i].second;
				if (t >= 0 && t < n + 1) res += m[t];
				if (v[i].first == j) m[v[i].second]++;
			}		
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
