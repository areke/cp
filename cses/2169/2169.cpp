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
#include <unordered_map>
#include <unordered_set>
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
	int n;
	cin >> n;
	vector<vector<int> > v;
	

	set<int> s;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		s.insert(x);
		s.insert(y);
		v.push_back({x, y, i});
	}
	unordered_map<int, int> m;
	
	int ind = 0;
	for (int x : s) {
		m[x] = ind++;
	}
	Seg<int> seg;
	seg.init(m.size());
	sort(v.begin(), v.end(), [&](vector<int> & a, vector<int> & b) {
		if (a[1] == b[1]) {
			return a[0] > b[0];
		}
		return a[1] < b[1];
	});
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		a[v[i][2]] = seg.query(m[v[i][0]], m[v[i][1]]);
		seg.upd(m[v[i][0]], seg.query(m[v[i][0]], m[v[i][0]]) + 1);
	}
	Seg<int> seg2;
	seg2.init(m.size());
	for (int i = n - 1; i >= 0; i--) {
		b[v[i][2]] = seg2.query(0, m[v[i][0]]);
		seg2.upd(m[v[i][0]], seg2.query(m[v[i][0]], m[v[i][0]]) + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}

	for (int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i == n - 1];
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
