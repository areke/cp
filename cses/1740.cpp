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
	int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    map<int, vector<pair<int, int> > > m;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000001;
        x2 += 1000001;
        y1 += 1000001;
        y2 += 1000001;
        
        if (x1 == x2) {
            m[x1].push_back({y1 + 1, y2 - 1});
        } else {
            v.push_back({x1 + 1, y1, 1});
            v.push_back({x2, y1, -1});
        }
    }
    sort(v.begin(), v.end());
    int p = 0;
    Seg<int> seg;
    seg.init(2000003);

    long long res = 0;
    for (int x = 1; x <= 2000001; x++) {
        while (p < v.size() && v[p][0] == x) {
            if (v[p][2] == 1) {
                seg.upd(v[p][1], 1);
            } else {
                seg.upd(v[p][1], 0);
            }
            p++;
        }
        for (int i = 0; i < m[x].size(); i++) {
            res += seg.query(m[x][i].first, m[x][i].second);
        }
    }
    cout << res << endl;
	return 0;
}
