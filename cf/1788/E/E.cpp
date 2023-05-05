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
	const T ID = -1e18;
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<long long> p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + v[i - 1];
	}
	vector<pair<long long, long long> > c(n + 1);
	for (int i =0; i <= n; i++) {
		c[i] = {p[i], i};
	}
	sort(c.begin(), c.end());
	map<long long, int> m;
	for (int i = 0; i <= n; i++) {
		m[c[i].first] = i;
	}
	Seg<long long> seg;
	seg.init(n + 2);
	vector<long long> dp(n + 1, 0);
	seg.upd(m[0], 0);
	
	for (int i = 1; i <= n; i++) {
		
		int low = 0;
		int high = n;
		int best = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			//cout << i << " ? " << mid << " " << val << endl;
			if (c[mid].first <= p[i]) {
				low = mid + 1;
				best = mid;
			} else {
				high = mid - 1;
			}
		}
		dp[i] = max(dp[i], dp[i - 1]);
		if (best >= 0) {
			dp[i] = max(dp[i], i + seg.query(0, best));
		}
		
		//if (n == 10) cout << i << " " << best << " " << dp[i]  << " " << c[best].first << " " << p[i] << " " << m[p[i]] << " " << seg.query(0, best) << endl;
		seg.upd(m[p[i]], max(seg.query(m[p[i]], m[p[i]]), dp[i] - i));
		
	}
	cout << dp[n] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
