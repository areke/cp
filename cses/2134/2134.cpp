#include <bits/stdc++.h>
using namespace std;



struct LCA {
	int n;
	const int LEVELS = 19;
	vector<vector<int > > v;

	vector<int> depth;

	vector<vector<int > > jump;
		
	vector<pair<int, int> > euler_tour;

	void getDepth(int x, int last) {
		if (last != -1) depth[x] = depth[last] + 1;
		for (int n : v[x]) {
			if (last == n) continue;
			getDepth(n, x);
		}
	}
	

	
	LCA(vector<vector<int> > & v) {
		this->v = v;
		this->n = v.size();
		depth.assign(n, 0);
		jump.resize(LEVELS);
		for (int i = 0; i < LEVELS; i++) {
			jump[i].assign(n, -1);
		}
		euler_tour.resize(n);
		getDepth(0, -1);

		int cnt = 0;
		// populate jump[i] with the 2^0th ancestor of i, and d with the euler

		function<void (int x, int & cnt, int last)> lca_dfs = [&](int x, int & cnt, int last) {
			jump[0][x] = last;
			int s = cnt;
			for (auto n : v[x]) {
				if (n == last) continue;
				lca_dfs(n, ++cnt, x);
			}
			int e = cnt;
			euler_tour[x] = {s, e};
		};



		lca_dfs(0, cnt, -1);

		for (int i = 1; i < jump.size(); i++) {
			for (int j = 0; j < n; j++) {
				auto old = jump[i - 1][j];
				if (old == -1) continue;
				auto next = jump[i - 1][old];
				jump[i][j] = next;
			}
		}
	}
	// given a vector<pair<int, int> > of the start and exit of the euler tour of d
	// return if a is an ancestor of b
	bool isAncestor(int a, int b) {
		return (euler_tour[a].first <= euler_tour[b].first && euler_tour[a].second >= euler_tour[b].second);
	}


	// jumps to the dth ancestor of x
	// returns the ancestor
	int jmp(int x, int d) {
		int ret = x;
		for (int i = 0; i < LEVELS; i++) {
			if ((1 << i) & d) {
				ret = jump[i][x];
				x = jump[i][x];
			}
			if (x == -1) return -1;
		}
		return ret;
	}

	int calc_lca(int a, int b) {
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
				best = anc;
			} else {
				low = mid + 1;
			}
		}

		return best;
	}
};

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

struct heavy_light {
	int n;
	Seg<int> seg;
	vector<int> a;
	vector<vector<int> > v;
	vector<int> c;
	vector<int> d;
	vector<int> p;
	LCA lca;
	vector<int> f;
	// position for querying in seg tree
	vector<int> pos;
	int cur = 0;


	int dfs1(int x, int last = -1) {
		c[x] = 1;
		if (last == -1) d[x] = 0;
		else d[x] = d[last] + 1;
		for (int n : v[x]) {
			if (n == last) continue;
			p[n] = x;
			c[x] += dfs1(n, x);
		}
		return c[x];
	}

	void decomp(int x, int h, int last = -1) {
		f[x] = h;
		pos[x] = cur++;
		for (int n : v[x]) {
			if (n == last) continue;
			if (2 * c[n] > c[x]) {
				decomp(n, h, x);
			}
		}
		for (int n : v[x]) {
			if (n == last) continue;
			if (2 * c[n] <= c[x]) {
				decomp(n, n, x);
			}
		}
	}

	heavy_light(vector<vector<int> > & v, LCA & lca, vector<int> a) : lca(lca) {
		this->v = v;
		n = v.size();
		c.assign(n, 0);
		d.assign(n, 0);
		p.assign(n, 0);
		f.assign(n, 0);
		pos.assign(n, 0);
		dfs1(0);

		decomp(0, 0);
		seg.init(n);
		for (int i = 0; i < n; i++) {
			seg.upd(pos[i], a[i]);
		}
	}

	void upd(int x, int val) {
		seg.upd(pos[x], val);
	}


	int query(int x, int y) {
		int res = max(seg.query(pos[x], pos[x]), seg.query(pos[y], pos[y]));
		int l = lca.calc_lca(x, y);
		while (x != y) {
			if (d[x] < d[y]) swap(x, y);
			if (f[x] == x) {
				res = max(res, seg.query(pos[x], pos[x]));
				x = p[x];
			}	else {
				if (d[f[x]] < d[l]) {
					res = max(res, seg.query(pos[l], pos[x]));
				} else {
					res = max(res, seg.query(pos[f[x]], pos[x]));
				}
				x = f[x];
			}
		}
		res = max(res, seg.query(pos[l], pos[l]));
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	LCA lca(v);
	heavy_light hl(v, lca, a);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, v;
			cin >> x >> v;
			x--;
			hl.upd(x, v);
		} else {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << hl.query(a, b) << " \n"[q == 0];
		}
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
