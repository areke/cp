#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <atcoder/lazysegtree>
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
using namespace atcoder;




template<class T> struct Seg2 {
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

struct starry {
    static int op_ss(int a, int b) { return std::min(a, b); }
    static int op_ts(int a, int b) { return a + b; }
    static int op_tt(int a, int b) { return a + b; }
    static int e_s() { return 1'000'000'000; }
    static int e_t() { return 0; }
};

using Seg = lazy_segtree<int,
                                starry::op_ss,
                                starry::e_s,
                                int,
                                starry::op_ts,
                                starry::op_tt,
                                starry::e_t>;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {

		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> vals(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			vals[i] = i;
		}
		Seg seg(n + 1);
		for (int i = 0; i <= n; i++) {
			seg.set(i, i);
		}

		Seg2<long long> seg2;
		Seg2<long long> seg3;
		seg2.init(n + 1);
		seg3.init(n + 1);
		long long cur = 0;
		long long s = 0;
		vector<long long> res(n);
		for (int i = 0; i < n; i++) {
			s += a[i];
			seg.apply(a[i], n, -1);
			seg2.upd(a[i], seg2.query(a[i], a[i]) + a[i]);
			int low = 1;
			int high = n;
			int best = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				int val = seg.prod(0, mid + 1);
				//cout << i << " : " << mid << " " << val << " " << seg.get(mid) << endl;
				if (val < 0) {
					best = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			
			if (best == -1) {
				cur++;
			} else {
				seg.apply(best, n, 1);
				s -= best;
			}
			
			//cout << s - (cur * (cur + 1) / 2) << endl;
			seg2.upd(a[i], seg2.query(a[i], a[i]) + a[i]);
			seg3.upd(a[i], seg3.query(a[i], a[i]) + 1);
			long long ans = s - (cur * (cur + 1) / 2);
			

			
			//cout << i << " wtf " << cur << " " << ans << " " << seg3.query(cur + 1, n) << endl;
			//ans -= seg3.query(cur + 1, n) * cur;
			
			res[i] = ans;
		}
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
