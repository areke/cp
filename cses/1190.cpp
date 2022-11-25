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


struct Node {
    long long lsum, rsum, tsum, msum;
    Node(long long a, long long b, long long c, long long d) {
        lsum = max(a, (long long)0);
        rsum = max(b, (long long)0);
        msum = max(c, (long long)0);
        tsum = d;
    }
};


template<class T> struct Seg {
	const T ID = Node(0, 0, 0, 0);
	T comb(T a, T b) {
        long long t = a.tsum + b.tsum;
        long long bestl = max(a.lsum, a.tsum + b.lsum);
        long long bestr = max(b.rsum, a.rsum + b.tsum);
        long long bestm = max(max(a.msum, b.msum), a.rsum + b.lsum);
        return Node(bestl, bestr, bestm, t);
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
    Seg<Node> seg;
    seg.init(n + 1);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        seg.upd(i + 1, Node(x, x, x, x));
    }
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        seg.upd(a, Node(b, b, b, b));
        cout << seg.query(0, n).msum << endl;
        //cout << max(seg.query(1, n).msum, (long long) 0) << endl;
    }

}