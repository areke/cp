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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

using namespace std;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> multi_ordered_set;
	

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
    return a + b;
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
		if (l > r) return 0;
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
	int k, n;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	Seg<long long> seg;
	seg.init(n);
	Seg<long long> seg2;
	seg2.init(n);
	unordered_map<long long, int> m;
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
	}
	int cnt = 0;
	for (auto x : s) {
		m[x] = cnt++;
	}
	multi_ordered_set ss;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		ss.insert(a[i]);
		res += a[i];
		seg.upd(m[a[i]], seg.query(m[a[i]], m[a[i]]) + a[i]);

		seg2.upd(m[a[i]], seg2.query(m[a[i]], m[a[i]]) + 1);

		if (ss.size() > k) {
			res -= a[i - k];
			seg.upd(m[a[i - k]], seg.query(m[a[i - k]], m[a[i - k]]) - a[i - k]);
			seg2.upd(m[a[i - k]], seg2.query(m[a[i - k]], m[a[i - k]]) - 1);
			ss.erase(ss.upper_bound(a[i - k]));
		}
		if (ss.size() == k) {
			long long med = *ss.find_by_order((k - 1) / 2);
			long long above = seg.query(m[med] + 1, n - 1);
			long long numabove = seg2.query(m[med] + 1, n - 1);
			long long below = seg.query(0, m[med] - 1);
			long long numbelow = seg2.query(0, m[med] - 1);
			//cout << med << " " << above << " " << numabove << " " << below << " " << numbelow << endl;
			long long ans = above - numabove * med + numbelow * med - below;
			cout << ans << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
