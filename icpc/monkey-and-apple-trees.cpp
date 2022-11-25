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
#include <assert.h>

using namespace std;

const long long BAD = -1;

struct node {
    int v, p, l, r;
    int tl, tr;
    node(int tl, int tr, int l, int r, int v, int p) {
        this->v = v;
        this->p = p;
        this->tl = tl;
        this->tr = tr;
        this->l = l;
        this->r = r;
    }
};

struct Seg {

    vector<node> seg;
    int cnt = 0;

    Seg(long long n, long long maxi) {
        seg.push_back(node(BAD, BAD, 1, maxi, 0, BAD));
        cnt++;
    }

    void prop(int ind) {
        long long mid = (seg[ind].l + seg[ind].r) / 2;
        if (seg[ind].tl == BAD) {
            seg.push_back(node(BAD, BAD, seg[ind].l, mid, 0, BAD));
            seg[ind].tl = cnt++;
        }
        if (seg[ind].tr == BAD) {
            seg.push_back(node(BAD, BAD, mid + 1, seg[ind].r, 0, BAD));
            seg[ind].tr = cnt++;
        }
        node cur = seg[ind];
        if (cur.p != BAD) {
            seg[cur.tl].v = (seg[cur.tl].r - seg[cur.tl].l + 1) * cur.p;
            seg[cur.tl].p = cur.p;
            seg[cur.tr].v = (seg[cur.tr].r - seg[cur.tr].l + 1) * cur.p;
            seg[cur.tr].p = cur.p;
        }
        cur.p = BAD;
    }

    void set(int cur, long long l, long long r, long long v) {
        long long tl = seg[cur].l;
        long long tr = seg[cur].r;
        if (l > tr || r < tl) return;
        if (l <= tl && r >= tr) {
            seg[cur].v = (seg[cur].r - seg[cur].l + 1) * v;
            seg[cur].p = v;
            return;
        }
        prop(cur);
        long long mid = (seg[cur].l + seg[cur].r) / 2;
        set(seg[cur].tl, l, r, v);
        set(seg[cur].tr, l, r, v);
        //cout << "WHAT " << cur << " " << seg[cur].tl << " " << seg[cur].tr << endl;
        seg[cur].v = seg[seg[cur].tl].v + seg[seg[cur].tr].v;
    }

    long long query(int cur, long long l, long long r) {
        long long tl = seg[cur].l;
        long long tr = seg[cur].r;
        if (l > tr || r < tl) return 0;
        if (l <= tl && r >= tr) {
            return seg[cur].v;
        }
        prop(cur);
        long long res = 0;
        res += query(seg[cur].tl, l, r);
        res += query(seg[cur].tr, l, r);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    set<int> vals;
    long long maxi = 1e9;
    Seg seg(30 * 100000, maxi);
    long long c = 0;
    
    for (int i = 0; i < n; i++) {
        long long d, x, y;
        cin >> d >> x >> y;
        x += c;
        y += c;
        //cout << " WHAT " << c << " " << x << " " << c + y << endl;
        if (d == 1) {
            long long tot = seg.query(0, x, y);
            cout << tot << endl;
            c = tot;
        } else {
            seg.set(0, x, y, 1);
        }
    }
}