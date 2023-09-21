#include <bits/stdc++.h>
using namespace std;

pair<int, int> MINI_ID = {1e7, -1};
pair<int, int> MAXI_ID = {-1, -1};

template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = {MINI_ID, MAXI_ID};
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		return {min(a[0], b[0]), max(a[1], b[1])};
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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> g(n, -1);

	vector<int> l(n, -1);

	Seg<array<pair<int, int>, 2> > seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		pair<int, int> p = {v[i], i};
		seg.upd(i, {p, p});
	}
	stack<int> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			g[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	s = {};
	for (int i = 0; i < n; i++) {
		while (!s.empty() && v[s.top()] > v[i]) {
			l[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	long long res = 0;
	vector<long long> dp(n + 1, 0);
	for (int i = n - 2; i >= 0; i--) {
		if (g[i] == -1) {
			dp[i] = 0;
		} else if (l[i] == -1) {
			dp[i] = n - i - 1;
		} else if (g[i] < l[i]) {
			auto mx = seg.query(i + 1, l[i]);
			dp[i] = dp[mx[1].second] + l[i] - i - 1;
		} else {
			auto mx = seg.query(i + 1, g[i]);
			dp[i] = dp[mx[0].second] + 1 - (g[i] - mx[0].second);
		}
		res += dp[i];
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
