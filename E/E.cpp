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

const long long BAD = -1e18;

struct node {
    long long v = 0;
    long long inc = 0;
    long long pushv = BAD;
    node(long long inc, long long v, long long pushv) {
        this->inc = inc;
        this->v = v;
        this->pushv = pushv;
    }
};


template<class T> struct Seg {
	const T ID = 0;
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


vector<long long> solve(vector<long long> & h, int n) {
	Seg<long long> s;
	s.init(n + 1);
	for (int i = 0; i < n; i++) {
		s.upd(i + 1, h[i] + i);
	}
	vector<long long> p(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + h[i];
	}
	vector<long long> res(n);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int high = n - 1;
		int low = i;
		int best = i;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (s.query(i, mid) + i <= h[i]) {
				best = max(best, mid);
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		res[i] = p[best] - p[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		vector<long long> a = solve(h, n);
		reverse(h.begin(), h.end());
		vector<long long> b = solve(h, n);
		reverse(b.begin(), b.end());
		long long tot = 0;
		for (int i = 0; i < n; i++) {
			tot += h[i];
		}
		long long res = 1e18;
		for (int i = 0; i < n; i++) {
			long long cur = a[i] + b[i] - h[i];
			res = min(tot - cur + 1, res);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
