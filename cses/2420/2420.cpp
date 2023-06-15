#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = (1ULL << 61) - 1;

const unsigned long long mod = (1ULL << 61) - 1;
const unsigned long long B = 31;


int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

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
    return (a + b) % MOD;
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
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	Seg<unsigned long long> seg;
	seg.init(n);

	Seg<unsigned long long> rev;
	rev.init(n);
	vector<unsigned long long> base(n, 0);
	base[0] = 1;
	for (int i = 1; i < n; i++) {
		base[i] = modmul(base[i - 1], B);
		base[i] %= MOD;
	}
	for (int i = 0; i < n; i++) {
		seg.upd(i, modmul(base[i], (s[i] - 'a')));
		rev.upd(i, modmul(base[n - i - 1], (s[i] - 'a')));
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int ind;
			char c;
			cin >> ind >> c;
			ind--;
			seg.upd(ind, modmul(base[ind], (c - 'a')));
			rev.upd(ind, modmul(base[n - ind - 1], (c - 'a')));
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if ((b - a + 1) % 2) {
				if ((modmul(seg.query(a, (a + b) / 2), base[n - b - 1])) == modmul(rev.query((a + b) / 2, b), base[a])) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				if ((modmul(seg.query(a, (a + b) / 2), base[n - b - 1])) == modmul(rev.query((a + b) / 2 + 1, b), base[a])) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
