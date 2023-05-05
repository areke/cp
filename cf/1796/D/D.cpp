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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, k, x;
		cin >> n >> k >> x;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = v[i] - x;
		}
		vector<long long> p(n + 1, 0);
		vector<long long> ap(n + 1, 0);
		
		ap[0] = 0;
		for (int i = 1; i <= n; i++) {
			p[i] += p[i - 1] + v[i - 1];
			ap[i] += ap[i - 1] + a[i - 1];
		}
		Seg<long long> seg;
		seg.init(n + 1);
		for (int i = 0; i <= n; i++) {
			seg.upd(i, ap[i]);
		}
		long long mini = 1e15;
		long long res = 0;
		if (x >= 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= 2 * k; j++) {
						if (i - j < 0) continue;
						long long can = min((long long)j, k);
						res = max(res, p[i] - p[i - j] + can * x - (j - can) * x);
				}
				if (i - k >= 0) {
					mini = min(ap[i - k], mini);
					if (i - k == 0) assert(mini == 0);
					res = max(res, ap[i] - mini + 2 * k * x);
				}
				
			}
		} else {
			mini = 0;
			for (int i = 1; i <= n - k; i++) {
				mini = min(ap[i], mini);
				res = max(res, ap[i] - mini);
			}
			for (int i = n - k + 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					long long inside = i - (n - k);
					res = max(res, ap[j] - ap[j - i] + inside * x * 2);
				}
				// at least k outside
				res = max(res, ap[i] - seg.query(i - (n - k), i));
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
