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

struct node {
	multiset<int> s;
	node(multiset<int> s) {
		this->s = s;
	}
};


template <class T>
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = node({});
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	int destroy(int l, int r, int tl, int tr, int ind, int p) {
		if (l > tr || r < tl) return 0;
		if (seg[ind].s.empty()) return 0;
		if (*(seg[ind].s.begin()) > p) return 0;
		if (l <= tl && r >= tr && tr == tl) {
			rem(ind, *(seg[ind].s.begin()));
			return 1;
		}
		int left = destroy(l, r, tl, (tl + tr) / 2, 2 * ind + 1, p);
		int right = destroy(l, r, (tl + tr) / 2 + 1, tr, 2 * ind + 2, p);	
		return left + right;
	}

	void rem(int ind, int x) {
		seg[ind].s.erase(seg[ind].s.find(x));
		if (ind == 0) return;
		rem((ind - 1) / 2, x);
	}

	void add(int ind, int x) {
		seg[ind].s.insert(x);
		if (ind == 0) return;
		add((ind - 1) / 2, x);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Seg<node> seg;
	seg.init(n);
	for (int i = 0; i < m; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			if (!seg.seg[x + seg.sz - 1].s.empty()) {
				int el = (*seg.seg[x + seg.sz - 1].s.begin());
				seg.rem(x + seg.sz - 1, el);
			}
			seg.add(x + seg.sz - 1, y);
		} else {
			int p;
			cin >> p;
			cout << seg.destroy(x, y - 1, 0, seg.sz - 1, 0, p) << endl;
		}
		//cout << seg.seg[0].s.size() << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
