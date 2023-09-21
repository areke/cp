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
    vector<string> v(n);
    Seg<int> a;
    a.init(3 * n + 5);
    Seg<int> b;
    b.init(3 * n + 5);
    int SHIFT = n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    // x - i >= |y - j|
    // x - y >= i - j, y >= j
    // x + y <= i + j, y <= j
    int cur = 0;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        int c = a.query(0,  x - y + SHIFT);
        int d = b.query(0, x + y + SHIFT);
        int num = c + d - cur;
        int val = v[x][y] - '0';
        if ((val + num) & 1) {
          cur++;
          a.upd(x - y + SHIFT, a.query(x - y + SHIFT, x - y + SHIFT) + 1);
          b.upd(x + y + SHIFT, b.query(x + y + SHIFT, x + y + SHIFT) + 1);
        }
      }
    }
    cout << cur << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
