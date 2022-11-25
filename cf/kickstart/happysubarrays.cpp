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
#include <cstring>
using namespace std;


template<class T> struct Seg {
	const T ID = 1e18;
	T comb(T a, T b) {
		return min(a, b);
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
	int tests;
	cin >> tests;
    int test = 0;
	while (tests--) {
        test++;
		int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> p(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + a[i - 1];
        }
        Seg<long long> seg;
        seg.init(n + 2);
        for (int i = 1; i <= n + 1; i++) {
            seg.upd(i, p[i - 1]);
        }
        vector<long long> sump(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sump[i] = sump[i - 1] + p[i];
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) continue;
            int low = i;
            int high = n;
            int best = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (seg.query(i + 1, mid + 1) < p[i]) {
                    high = mid - 1;
                } else {
                    best = mid;
                    low = mid + 1;
                }
            }
            //cout << i << " " << best << " " << sump[best] - sump[i] << endl;
            res += sump[best] - sump[i] - (best - i) * p[i];
        }
        cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}
