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
#include <unordered_map>
#include <unordered_set>
#include <functional>

#include <queue>
#include <list>
#include <assert.h>
#include <array>
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

const int LEVELS = 21;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> p(n);
		vector<vector<int> > v(n);
		vector<int> o(n);
		for (int i = 1; i < n; i++) {
			cin >> p[i];
			p[i]--;
			v[i].push_back(p[i]);
			v[p[i]].push_back(i);
		}

		vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
			
		vector<pair<int, int> > d(n);
		int cnt = 0;
		// populate jump[i] with the 2^0th ancestor of i, and d with the euler

		function<void (int x, int & cnt, int last)> dfs = [&](int x, int & cnt, int last) {
			jump[0][x] = last;
			int s = cnt;
			o[x] = cnt;
			for (auto n : v[x]) {
				if (n == last) continue;
				dfs(n, ++cnt, x);
			}
			int e = cnt;
			d[x] = {s, e};
		};



		dfs(0, cnt, -1);


		Seg<int> seg;
		seg.init(n + 1);
		seg.upd(0, 1);
		
		for (int i = 1; i < jump.size(); i++) {
			for (int j = 0; j < n; j++) {
				auto old = jump[i - 1][j];
				if (old == -1) continue;
				auto next = jump[i - 1][old];
				jump[i][j] = next;
			}
		}

		// given a vector<pair<int, int> > of the start and exit of the euler tour of d
		// return if a is an ancestor of b
		auto isAncestor = [&](int a, int b) {
			return (d[a].first <= d[b].first && d[a].second >= d[b].second);
		};

		// jumps to the dth ancestor of x
		// returns the ancestor
		auto jmp = [&](int x, int d) {
			int ret = x;
			for (int i = 0; i < LEVELS; i++) {
				if ((1 << i) & d) {
					ret = jump[i][x];
					x = jump[i][x];
				}
				if (x == -1) return -1;
			}
			return ret;
		};

		// return lca of a and b
		auto lca = [&](int a, int b) {
			int low = 0;
			int high = 1 << LEVELS;
			int best = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				int anc = jmp(a, mid);
				if (anc == -1) {
					high = mid - 1;
					continue;
				}
				if (isAncestor(anc, b)) {
					high = mid - 1;
					best = mid;
				} else {
					low = mid + 1;
				}
			}

			return best;
		};
		int c = 0;
		int m = 0;
		int sz = 1;
		for (int i = 1; i < n; i++) {
			sz++;
			seg.upd(o[i], 1);
			if (!isAncestor(c, i)) {
				int cand = p[c];
				int num = sz - seg.query(d[c].first, d[c].second);
				//cout << seg.query(d[c].first, d[c].second) << endl;
				m = max(num, m);
				if (m > sz / 2) {
					assert(m == sz / 2 + 1);
					c = cand;
					m = sz / 2;
				}
			} else {
				int dist = lca(i, c);
				int cand = jmp(i, dist - 1);
				assert(p[cand] == c);
				int num = seg.query(d[cand].first, d[cand].second);
				m = max(num, m);
				if (m > sz / 2) {
					assert(m == sz / 2 + 1);
					c = cand;
					m = sz / 2;
				}
			}
			cout << sz - 2 * m << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
