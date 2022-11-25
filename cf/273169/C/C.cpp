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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

struct Seg {
	const pair<long long, int> ID = make_pair(1e18, 0);
	pair<long long, int> comb(pair<long long, int> a, pair<long long, int> b) {
		if (a.first == b.first) {
			return make_pair(a.first, a.second + b.second);
		}
		return min(a, b);
	}
	int n;
	vector<pair<long long, int> > seg;
	void init(int _n) {
		n = _n;
		seg.assign(2*n, ID);
	}
	void pull(int p) {
		seg[p] = comb(seg[2*p], seg[2*p+1]);
	}

	void upd(int p, long long val) {
		seg[p += n] = make_pair(val, 1);
		for (p /= 2; p; p/= 2) {
			pull(p);
		}
	}
	pair<long long, int> query(int l, int r) {
		pair<long long, int> ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	
	Seg seg;
	seg.init(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		seg.upd(i + 1, arr[i]);
	}
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, v;
			cin >> i >> v;
			seg.upd(i + 1, v);
		} else {
			int l, r;
			cin >> l >> r;
			pair<long long, int> p = seg.query(l + 1, r);
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}
