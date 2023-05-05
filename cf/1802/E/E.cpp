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
#include <assert.h>
#include <array>
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			tot += k;
			int last = -1;
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				if (x > last) {
					v[i].push_back(x);
					last = x;
				}
			}
		}
		vector<pair<int, int> > s(n);
		set<int> all;
		for (int i = 0; i < v.size(); i++) {
			pair<int, int> cur = {-1, i};
			for (int j = 0; j < v[i].size(); j++) {
				all.insert(v[i][j]);
				cur.first = max(cur.first, v[i][j]);
			}
			s[i] = cur;
		}
		int ind = 1;
		map<int, int> m;
		m[0] = 0;
		for (int x : all) {
			m[x] = ind;
			ind++;
		}
		Seg<int> seg;
		seg.init(tot + 1);
		sort(s.begin(), s.end());
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			int cur = s[i].second;
			int curbest = seg.query(m[s[i].first], m[s[i].first]);
			map<int, int> last;
			for (int j = 0; j < v[cur].size(); j++)  {
				int best = seg.query(0, m[v[cur][j]] - 1);
				last[m[v[cur][j]]] = seg.query(m[v[cur][j]], m[v[cur][j]]);
				best = best + 1;
				best = max(best, last[m[v[cur][j]]]);
				seg.upd(m[v[cur][j]], best);
				//cout << cur << " " << v[cur].size() << " " << j << " " << m[v[cur][j]] - 1 << " " << best <<  endl;
				curbest = max(curbest, best);
			}
			for (auto it : last) {
				seg.upd(it.first, it.second);
			}
			seg.upd(m[s[i].first], curbest);
			res = max(res, curbest);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
