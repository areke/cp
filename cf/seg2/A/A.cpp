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
	T ID = 0;
	vector<T> seg;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(sz * 2, ID);
	}

	T comb(T a, T b) {
		return a + b;
	}

	T query(int l, int r) {
		return query(l, r, 0, sz - 1, 0);
	}
	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) return seg[ind];
		if (l > tr || r < tl) return ID;
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2);
		return comb(left, right);
	}
	
	void pull(int ind) {
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
		if (ind == 0) return;
		pull((ind - 1) / 2); 
	}

	void upd(int ind, int v) {
		seg[ind + sz - 1] = v;
		pull((ind + sz - 2) / 2);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> p(n);
	vector<int> res(n, 0);
	Seg<long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		p[v[i] - 1] = i;
	}
	for (int i = n - 1; i >= 0; i--) {
		res[p[i]] = seg.query(0, p[i]);
		seg.upd(p[i], 1);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
