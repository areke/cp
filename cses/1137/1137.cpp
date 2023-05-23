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
#include <functional>

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

// SOLVES https://cses.fi/problemset/task/1688

const int LEVELS = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> p(n, -1);
	vector<vector<int > > v(n);
	Seg<long long> seg;
	seg.init(n);
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}


	vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
		
	vector<pair<int, int> > d(n);
	int cnt = 0;
	// populate jump[i] with the 2^0th ancestor of i, and d with the euler
	vector<int> ee(n, 0);
	function<void (int x, int & cnt, int last)> dfs = [&](int x, int & cnt, int last) {
		jump[0][x] = last;
		ee[x] = cnt;
		int s = cnt;
		for (auto n : v[x]) {
			if (n == last) continue;
			dfs(n, ++cnt, x);
		}
		int e = cnt;
		d[x] = {s, e};
	};
	dfs(0, cnt, -1);
	for (int i = 0; i < n; i++) {
		seg.upd(ee[i], a[i]);
	}
	
	

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int s, x;
			cin >> s >> x;
			s--;
			seg.upd(ee[s], x);
		} else {
			int s;
			cin >> s;
			s--;
			cout << seg.query(d[s].first, d[s].second) << endl;
		}
	}







	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
