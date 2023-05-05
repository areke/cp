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

const long long BAD = -1e18;

long long MOD = 1e9 + 7;

struct node {
    mi v = 0;
    mi inc = 0;
    long long pushv = BAD;
    mi multi = 1;
    node(mi inc, mi v, long long pushv, mi multi) {
        this->inc = inc;
        this->v = v;
        this->pushv = pushv;
        this->multi = multi;
    }
};

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */

const long long MOD = 1e9 + 7;

struct mi { // WARNING: needs some adjustment to work with FFT
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(long long _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, long long p) { assert(p >= 0); // won't work for negative p
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

struct LazySeg {
	
	vector<node> seg;
    int maxn;
	Seg(int n) {
        seg.assign(4 * n + 1, node(0, 0, BAD));
    }

    // parent is x / 2, left child is 2x, right child is 2x + 1
    // one indexed
    void set(int cur, int tl, int tr, int l, int r, long long v) {
        if (r < tl || l > tr) return;
        // cout << "SET " << cur << " " << tl << " " << tr << " " << l << " " << r << " " << v << endl;
        if (l <= tl && r >= tr) {
            seg[cur].v = ((long long)(tr - tl + 1)) * v;
            seg[cur].pushv = v;
            seg[cur].inc = 0;
            seg[cur].multi = 1;
            //prop(cur, tl, tr);
            return;
        }
        prop(cur, tl, tr);
        int mid = (tl + tr) / 2;
        set(2 * cur, tl, mid, l, r, v);
        set(2 * cur + 1, mid + 1, tr, l, r, v);
        seg[cur].v = seg[2 * cur].v + seg[2 * cur + 1].v;
    }

    void inc(int cur, int tl, int tr, int l, int r, long long v) {
        if (r < tl || l > tr) return;
        if (l <= tl && r >= tr) {
            seg[cur].v += v * ((long long)(tr - tl + 1));
            seg[cur].inc += v;
            return;
        }
        prop(cur, tl, tr);
        int mid = (tl + tr) / 2;
        inc(2 * cur, tl, mid, l, r, v);
        inc(2 * cur + 1, mid + 1, tr, l, r, v);
        seg[cur].v = seg[2 * cur].v + seg[2 * cur + 1].v;
    }

    void mult(int cur, int tl, int tr, int l, int r, long long v) {
        if (r < tl || l > tr) return;
        if (l <= tl && r >= tr) {
            seg[cur].v *= v;
            seg[cur].multi *= v;
           // prop(cur, tl, tr);
            return;
        }
        prop(cur, tl, tr);
        int mid = (tl + tr) / 2;
        mult(2 * cur, tl, mid, l, r, v);
        mult(2 * cur + 1, mid + 1, tr, l, r, v);
        seg[cur].v = seg[2 * cur].v + seg[2 * cur + 1].v;
    }
    void prop(int cur, int tl, int tr) {
        if (seg[cur].pushv != BAD) {
            mi val = seg[cur].pushv * (tr - tl + 1) / 2;
            seg[2 * cur] = node(0, val, seg[cur].pushv, seg[cur].multi);
            seg[2 * cur + 1] = node(0, val, seg[cur].pushv, seg[cur].multi);
        }
        mi val = seg[cur].inc * (tr - tl + 1) / 2;
        seg[2 * cur].v += val;
        seg[2 * cur].inc += seg[cur].inc;
        seg[2 * cur].multi *= seg[cur].multi;
        seg[2 * cur + 1].v += val;
        seg[2 * cur + 1].inc += seg[cur].inc;
        seg[2 * cur + 1].multi *= seg[cur].multi;
        seg[cur].pushv = BAD;
        seg[cur].inc = 0;
        seg[cur].multi = 1;
    }

    long long query(int cur, int tl, int tr, int l, int r) {
        if (r < tl || l > tr) return 0;
        prop(cur, tl, tr);
        if (l <= tl && r >= tr) {
            return seg[cur].v;
        }
        int mid = (tl + tr) / 2;
        long long left = query(2 * cur, tl, mid, l, r);
        long long right = query(2 * cur + 1, mid + 1, tr, l, r);
        return left + right;
    }

};

int main() {

    long long n, q;
    cin >> n >> q;
    int maxi = 262144;
    Seg seg(maxi);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        seg.set(1, 1, maxi, i + 1, i + 1, x);
    }

    for (int i = 0; i < q; i++) {
        long long t, a, b, x;
        cin >> t;
        //cout << i << " WHAT" << endl;
        if (t == 1) {
            cin >> a >> b >> x;
            seg.inc(1, 1, maxi, a, b, x);
        } else if (t == 2) {
            cin >> a >> b >> x;
            seg.set(1, 1, maxi, a, b, x);
        } else {
            cin >> a >> b;
            cout << seg.query(1, 1, maxi, a, b) << endl;
        }
        /*
        for (int j = 0; j <= 2 * n + 1; j++) {
            cout << seg.seg[i].v << " ";
        }
        cout << endl;*/
    }
	return 0;
}
