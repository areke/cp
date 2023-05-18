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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


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
    return max(a, b);
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

	int n;
	cin >> n;
	vector<vector<int> > v(n);

	set<long long> s;
	for (int i = 0; i < n; i++) {
		vector<int> x = {0, 0, 0};
		for (int j = 0; j < 3; j++) {
			cin >> x[j];
		}
		s.insert(x[0]);
		s.insert(x[1]);
		v[i] = x;
	}
	unordered_map<long long, int> m;
	int cnt = 1;
	for (auto x : s) {
		m[x] = cnt++;
	}

	sort(v.begin(), v.end(), [](auto & a, auto & b) {
		return a[1] < b[1];
	});
	Seg<long long> seg;
	seg.init(s.size() + 1);
	for (int i = 0; i < n; i++) {
		long long cur = seg.query(m[v[i][1]], m[v[i][1]]);
		seg.upd(m[v[i][1]], max(cur, seg.query(0, m[v[i][0]] - 1) + v[i][2]));
	}
	cout << seg.query(0, s.size()) << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
