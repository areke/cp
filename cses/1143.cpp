// Solves https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A


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

int main() {
	int n, m;
	cin >> n >> m;
    Seg<long long> seg;
    seg.init(n + 1);
    vector<long long> c(n + 1, 0);
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        seg.upd(i + 1, h);
        c[i + 1] = h;
    }
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        int low = 1;
        int high = n;
        int found = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (seg.query(0, mid) >= x) {
                high = mid - 1;
                found = mid;
            } else {
                low = mid + 1;
            }
        }
        c[found] -= x;
        seg.upd(found, c[found]);
        cout << found << " ";
    }
    cout << endl;
	return 0;
}
