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


template <class T> 
struct Seg {
	vector<T> seg;
	int sz;
	const T ID = 0;
	void init(int n) {
		sz = 1;
		while (sz <= n) sz *= 2;
		seg.assign(2 * sz, ID);
	}

	T comb(T a, T b) {
    return max(a, b);
	}

	T query(int l, int r, int tl, int tr, int ind) {
		if (l <= tl && r >= tr) {
			return seg[ind];
		}
		if (l > tr || r < tl) return ID;
		T left = query(l, r, tl, (tl + tr) / 2, 2 * ind + 1);
		T right = query(l, r, (tl + tr ) / 2 + 1, tr, 2 * ind + 2);
		return comb(left, right); 
	}

	void pull(int ind) {
		seg[ind] = comb(seg[2 * ind + 1], seg[2 * ind + 2]);
		if (ind == 0) return;
		pull((ind - 1) / 2);
	}

	void upd(int ind, T v) {
		seg[ind + sz - 1] = v;
		pull((ind + sz - 2) / 2); 
	}
};

struct DSUrb {
	int comp = 0;
	vector<int> e; void init(int n) { e = vector<int>(n,-1); comp = n; }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,4> > mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) { mod.push_back({-1,-1,-1,-1}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		comp--;
		mod.push_back({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x; return 1;
	}
	int components() {
		return comp;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

void dfs(int x, int & cnt, vector<vector<pair<int, int> > > & v, vector<pair<int, int> > & p, vector<pair<int, int> > & d, int last, int sz) {
	p[x] = {last, sz};
	int s = cnt;
	for (auto n : v[x]) {
		if (n.first == last) continue;
		dfs(n.first, ++cnt, v, p, d, x, n.second);
	}
	int e = cnt;
	d[x] = {s, e};
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	int tot = 0;

		// y no work D:
	for (int test = 1; test <= tests; test++) {
		int n, m, q;
		cin >> n >> m >> q;
		vector<pair<int, int> > e;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			e.push_back({x, y});
		}
		DSUrb dsu;
		dsu.init(n);
		vector<vector<pair<int, int> > > v(n);
		for (int i = 0; i < m; i++) {
			if (!dsu.sameSet(e[i].first, e[i].second)) {
				dsu.unite(e[i].first, e[i].second);
				v[e[i].first].push_back({e[i].second, i + 1});
				v[e[i].second].push_back({e[i].first, i + 1});
			}
		}
		vector<pair<int, int> > d(n);
		vector<int> res(n, 1e9);
		vector<vector<pair<int, int> > > jump(19, vector<pair<int, int> >(n, {-1, -1}));
		int cnt = 0;
		dfs(0, cnt, v, jump[0], d, -1, -1);
		for (int i = 1; i < jump.size(); i++) {
			for (int j = 0; j < n; j++) {
				auto old = jump[i - 1][j];
				if (old.first == -1) {
					jump[i][j] = old;
					continue;
				}
				auto next = jump[i - 1][old.first];
				jump[i][j] = {next.first, max(next.second, old.second)};
			}
		}

		auto isAncestor = [&](int a, int b, auto & d) {
			return (d[a].first <= d[b].first && d[a].second >= d[b].second);
		};
		
		auto jmp = [&](int x, int d, auto & jump) {
			pair<int, int> ret = {x, 0};
			for (int i = 0; i < 19; i++) {
				if ((1 << i) & d) {
					ret.first = jump[i][x].first;
					ret.second = max(ret.second, jump[i][x].second);
					x = jump[i][x].first;
				}
				if (x == -1) return (pair<int, int>){-1, -1};
			}
			return ret;
		};

		// return lca and distance
		auto lca = [&](int a, int b, auto & d, auto & jump) {
			int low = 0;
			int high = 1 << 19;
			pair<int, int> best = {-1, -1};
			while (low <= high) {
				int mid = (low + high) / 2;
				int anc = jmp(a, mid, jump).first;
				if (anc == -1) {
					high = mid - 1;
					continue;
				}
				if (isAncestor(anc, b, d)) {
					high = mid - 1;
					best = {anc, mid};
				} else {
					low = mid + 1;
				}
			}

			return best;
		};
		for (int i = 0; i < n - 1; i++) {
			int d1 = lca(i, i + 1, d, jump).second;
			
			res[i] = jmp(i, d1, jump).second;

			int d2 = lca(i + 1, i, d, jump).second;
			int maxi = jmp(i, d1, jump).second;
			res[i] = max(res[i], jmp(i + 1, d2, jump).second);
		}
		Seg<int> seg;
		seg.init(n - 1);
		for (int i = 0; i < n - 1; i++) {
			seg.upd(i, res[i]);
		}
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			if (l == r) { 
				cout << 0 << " \n"[i == q - 1];
			} else {
				cout << seg.query(l, r - 1, 0, seg.sz - 1, 0) << " \n"[i == q - 1];
			}
			
		}


	}	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
