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

template <class T> 
struct Seg {
	int sz;
	vector<T> seg;
	const T ID = 0;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
		return a + b;
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) return seg[ind];
		if (l > tr || r < tl) return ID;
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
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

	void upd(int ind, T val) {
		seg[ind + sz - 1] = val;
		pull((ind + sz - 2) / 2);
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	n *= 2;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	Seg<long long> seg;
	seg.init(n);
	map<int, vector<int> > m;
	for (int i = 0; i < n; i++) {
		m[v[i]].push_back(i);
	}
	vector<int> res(n, 0);
	for (int i = 0; i < n; i++) {
		if (m[v[i]][0] == i) {
			
			
		} else {
			res[v[i] - 1] = seg.query(m[v[i]][0], n - 1);
			seg.upd(m[v[i]][0], 1);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		cout << res[i];
		if (i == n / 2 - 1) cout << endl;
		else cout << " ";
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
