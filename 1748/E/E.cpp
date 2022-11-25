#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

long long MOD = 1e9 + 7;

template<class T> struct Seg {
	const T ID = -1;
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

	T get(int ind) {
		return seg[ind + n];
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

int get_max(int l, int r, Seg<long long> & seg) {
	int low = l;
	int high = r;
	int maxi = seg.query(l, r);
	int best = r;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (seg.query(l, mid) == maxi) {
			best = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return best;
}

long long cnt = 0;
long long maxn, maxm;

/*
1
5 10000
1 5 4 2 3



1
5 5
1 2 3 1 2
*/

vector<long long> solve(long long l, long long r, Seg<long long> & seg) {
	
	if (l > r) {
		return vector<long long>(maxm + 1, 1);
	}
	cnt++;
	int maxi = get_max(l + 1, r + 1, seg);
	maxi--;
	vector<long long> res(maxm + 1, 0);
	vector<long long> left = solve(l, maxi - 1, seg);
	vector<long long> right = solve(maxi + 1, r, seg);
	for (int i = 1; i <= maxm; i++) {
	//	cout << l << " " << r << " " << left[i] << " " << right[i] << endl;
		res[i] = res[i - 1] + (left[i - 1] * right[i]) % MOD;
		res[i] %= MOD;
	}
	//cout << dp.size() << endl;
	//cout << l << " " << r << " " << m << " " << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		cnt =0 ;
		long long m, n;
		cin >> n >> m;
		maxn = n;
		maxm = m;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		Seg<long long> seg;
		seg.init(n + 1);
		for (int i = 0; i < n; i++) {
			seg.upd(i + 1, a[i]);
		}
		cout << solve(0, n - 1, seg)[m] << endl;
		//cout << cnt << endl;
	}
	return 0;
}
