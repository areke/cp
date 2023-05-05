#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


template<class T> struct Seg {
	const T ID = 1e9;
	T comb(T a, T b) {
		return min(a, b);
	}
	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}

	T get(int p) {
		return seg[n + p];
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
	int tests = 1;
	while (tests--) {
		int n, q;
		cin >> n >> q;
		Seg<long long> rows;
		rows.init(n + 1);
		

		Seg<long long> cols;
		cols.init(n + 1);
		for (int i = 0; i < n; i++) {
			rows.upd(i + 1, 0);
			cols.upd(i + 1, 0);
		}
		for (int i = 0; i < q; i++) {
			int t;
			cin >> t;
			if (t == 1) {
				int x, y;
				cin >> x >> y;
				rows.upd(x, rows.get(x) + 1);
				cols.upd(y, cols.get(y) + 1);
			} else if (t == 2) {
				int x, y;
				cin >> x >> y;
				rows.upd(x, rows.get(x) - 1);
				cols.upd(y, cols.get(y) - 1);
			} else {
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				long long mini1 = rows.query(x1, x2);
				long long mini2 = cols.query(y1, y2);
				if (mini1 == 0 && mini2 == 0) {
					cout << "No" << endl;
				}  else {
					cout << "Yes" << endl;
				}
			}
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
