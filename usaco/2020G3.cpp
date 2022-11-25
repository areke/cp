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
        p += n;
        if (val < seg[p]) return;
		seg[p] = val;
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

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n, p;
    ifstream fin("boards.in");
    ofstream fout("boards.out");
    fin >> n >> p;
    //priority_queue<pair<long long, long long> > pq;
    map<pair<int, int>, pair<int, int> > m;
    map<pair<int, int>, pair<int, int> > r;
    set<int> ys;
    map<int, int> yind;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long> >  > pq;
     
    for (int i = 0; i < p; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        m[make_pair(x1, y1)] = make_pair(x2, y2);
        r[make_pair(x2, y2)] = make_pair(x1, y1);
        ys.insert(y1);
        ys.insert(y2);
        pq.push(make_pair(x1, y1));
    }
    int cnt = 1;
    Seg<long long> seg;
    seg.init(2 * p + 1);
    for (auto it : ys) {
        yind[it] = cnt;
        cnt++;
    }
    

    map<pair<int, int>, long long> maxSave;

    while (!pq.empty()) {
        pair<long long, long long> p = pq.top();
        if (m.count(p)) {
            maxSave[p] = seg.query(0, yind[p.second]);
            pq.push(m[p]);
        } else {
            long long ms = maxSave[r[p]] + dist(r[p], p);
            //cout << ms << endl;
            seg.upd(yind[p.second], ms);
           // cout << "HU" << endl;
        }
        pq.pop();
    }
    long long res = 2 * (n) - seg.query(0, 2 * p);
    fout << res << endl;

}