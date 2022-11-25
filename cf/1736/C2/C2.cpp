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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

template<class T> struct Seg {
	const T ID = 0;
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


int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> v(n);
		Seg<long long> seg;
		seg.init(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v[i] -= (i + 1);
		}
		for (int i = 0; i < n; i++) {
			seg.upd(i + 1, v[i]);
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			int low = i;
			int high = n - 1;
			int ind = (i - 1);
			while (low <= high) {
				int mid = (low + high) / 2;
				if (seg.query(i, mid + 1) >= -i) {
					ind = max(ind, mid);
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			//cout << i << " " << ind << endl;
			res += ind - i + 1;
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int p, x;
			cin >> p >> x;
			int prev = v[x];
			seg.upd(p + 1, x - (p + 1));

			seg.upd(p + 1, v[p]);
		}
		cout << res << endl;
	}
	return 0;
}
