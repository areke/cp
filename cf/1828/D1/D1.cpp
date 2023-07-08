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

typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<int> g(n, 0);
		stack<int> s;
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && v[i] > v[s.top()]) {
				g[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		while (!s.empty()) {
			g[s.top()] = -1;
			s.pop();
		}

		vector<int> l(n, 0);
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && v[i] < v[s.top()]) {
				l[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		while (!s.empty()) {
			l[s.top()] = -1;
			s.pop();
		}
		Seg<long long> seg;
		seg.init(n);
		for (int i = 0; i < n; i++) {
			seg.upd(i, v[i]);
		}
		long long res = 0;
		vector<long long> dp(n, 0);


		for (int i = 1; i < n; i++) {
			if (v[i] > v[i - 1]) {
				dp[i] = dp[i - 1] + g[i] + 1;
			} else {
				long long dpli1 = l[i] == -1 ? 0 : dp[l[i]];
				dp[i] = dpli1 + (long long)(l[i] + 1) * (i - 1 - l[i]);
				dp[i] += (long long)(i - 1 - l[i]) *(i - 1 - l[i] + 1) / 2;
				int low = 0;
				int high = l[i];
				int best = -1;
				while (low <= high) {
					int mid = (low + high) / 2;
					if (seg.query(mid, l[i]) > v[i]) {
						best = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
				dp[i] += best + 1;
			}
			res += dp[i];
		}
		// 0 0 0 5 5 13 18 25 25 41 50 50

		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
