#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long swapn = 0;
int lev, lv;
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
				cout << lv << " " << swapn << endl;
				if (swapn & lv) {
					cout << "K" << endl;
					swap(a, b);
				}
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
		lv = lev;
		
		for (l += n, r += n+1; l < r; l /= 2, r /= 2, lv /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra,rb);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
		lev = (1 << n);
		lv = (1 << n);
    int size = 1 << n;

    vector<long long> a(size);
    for (int i = 0; i < size; ++i) {
			
      cin >> a[i];
    }
		Seg<Node> seg;
		seg.init(size);
		for (int i = 0; i < size; i++) {
			seg.upd(i, Node(a[i], a[i], a[i], a[i]));
		}

    int q;
    cin >> q;
		cout << seg.query(0, size - 1).msum << endl;
    for (int qq = 0; qq < q; qq++) {
			int k;
			cin >> k;
			swapn ^= (1 << k);
			cout << seg.query(0, size - 1).msum << endl;
		}
}
