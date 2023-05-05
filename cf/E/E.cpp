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

	int get(int p) {
		return seg[n + p];
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
	int n;
	cin >> n;
	vector<long long> a(n);
	set<long long> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	map<long long, int> m;
	int cnt = 0;
	for (int x : s) {
		m[x] = cnt++;
	}
	
	Seg<long long> l;
	Seg<long long> r;
	l.init(n);
	r.init(n);
	for (int i = 0; i < n; i++) {
		r.upd(m[a[i]], r.get(m[a[i]]) + 1);
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		r.upd(m[a[i]], r.get(m[a[i]]) - 1);
		if (i > 0 && i < n - 1) {
			long long left = l.query(m[a[i]] + 1, n - 1);
			long long right = r.query(0, m[a[i]] - 1);
			res += left * right;
		}
		l.upd(m[a[i]], l.get(m[a[i]]) + 1);
		
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
