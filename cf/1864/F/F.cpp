#include <bits/stdc++.h>
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
 
 
 
template<class T> struct Seg2 {
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
 
  int get(int p) {
    return seg[p + n];
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
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  vector<vector<int> > m(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    m[v[i]].push_back(i);
  }
  vector<array<int, 3> > queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][2] = i;
  }
  Seg<int> seg;
  seg.init(n + 1);
  Seg2<int> seg2;
  seg2.init(n + 1);
  Seg2<int> seg3;
  seg3.init(n + 1);
  vector<array<int, 2> > breaks;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)m[i].size() - 1; j++) {
      int l = m[i][j];
      int r = m[i][j + 1];
      int q = seg.query(l, r);
      if (q != 0) {
        breaks.push_back({q, i});
      }
    }
    for (int j = 0; j < m[i].size(); j++) {
      seg.upd(m[i][j], i);
    }
  }
 
  sort(queries.begin(), queries.end());
  sort(breaks.begin(), breaks.end());
  int p = ((int)breaks.size()) - 1;
  
  for (int i = 0; i < n; i++) {
    seg3.upd(v[i], 1);
  }
  vector<int> res(q);
  for (int i = q - 1; i >= 0; i--) {
    int l = queries[i][0];
    int r = queries[i][1];
    while (p >= 0 && breaks[p][0] >= l) {
      seg2.upd(breaks[p][1], seg2.get(breaks[p][1]) + 1);
      p--;
    }
    res[queries[i][2]] = seg3.query(l, r) + seg2.query(l, r);
 
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << "\n";
  }
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}
