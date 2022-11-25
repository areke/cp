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
	const T ID = 0;
	T comb(T a, T b) {
		return a + b;
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

    T get(int p) {
        return seg[p + n];
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
    int test = 0;
	cin >> tests;
	while (tests--) {
        test++;
        long long n, k, x, d;
        cin >> n >> k >> x >> d;
        long long m;
        cin >> m;
        map<int, vector<int> > open;
        map<int, vector<int> > closed;
        for (int i = 0; i < m; i++) {
            int p, a, b;
            cin >> p >> a >> b;
            open[a + 1].push_back(p);
            closed[b].push_back(p);
        } 
        map<int, int> meetings;
        Seg<long long> seg;
        seg.init(m + 2);
        Seg<long long> sumseg;
        sumseg.init(m + 2);
        seg.upd(1, n);
        long long res = 1e9;
        for (int i = 0; i <= d; i++) {
            //cout << i << " what" << endl;
            for (int j = 0; j < open[i].size(); j++) {
                int last = meetings[open[i][j]];
                int cur = meetings[open[i][j]] + 1;
                meetings[open[i][j]]++;
                
                seg.upd(cur + 1, seg.get(cur + 1) + 1);
                sumseg.upd(cur + 1, sumseg.get(cur + 1) + cur);
                seg.upd(last + 1, seg.get(last + 1) - 1);
                sumseg.upd(last + 1, sumseg.get(last + 1) - last);
            }
            //cout << i << " WUT" << endl;
            for (int j = 0; j < closed[i - x].size(); j++) {
                int last = meetings[closed[i - x][j]];
                int cur = meetings[closed[i - x][j]] - 1;
                meetings[closed[i - x][j]]--;
                seg.upd(cur + 1, seg.get(cur + 1) + 1);
                sumseg.upd(cur + 1, sumseg.get(cur + 1) + cur);
                seg.upd(last + 1, seg.get(last + 1) - 1);
                sumseg.upd(last + 1, sumseg.get(last + 1) - last);
            }
            int low = 0;
            int high = m;
            int best = 1e9;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (seg.query(1, mid + 1) >= k) {
                    high = mid - 1;
                    best = mid;
                } else {
                    low = mid + 1;
                }
            }

            
            long long val = sumseg.query(1, best + 1);
            
            int num = seg.query(1, best + 1);
            if (num > k) {
                val -= (num - k) * best;
            }
            if (i >= x) res = min(res, val);
            //cout << res << endl;
        }
        cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}
