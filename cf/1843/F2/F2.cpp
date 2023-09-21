#include <bits/stdc++.h>
using namespace std;

// solves https://codeforces.com/problemset/problem/1843/F2

struct node {
	int maxi = 0, sufmax = 0, prefmax = 0;
	int mini = 0, sufmin = 0, prefmin = 0;
	int tot = 0;

	// NOT COMMUTATIVE
	node operator+(node const & b) {
		node ret;
		ret.maxi = max({maxi, b.maxi, sufmax + b.prefmax});
		ret.sufmax = max(b.sufmax, b.tot + sufmax);
		ret.prefmax = max(prefmax, tot + b.prefmax); 

		ret.mini = min({mini, b.mini, sufmin + b.prefmin});
		ret.sufmin = min(b.sufmin, b.tot + sufmin);
		ret.prefmin = min(prefmin, tot + b.prefmin); 
		ret.tot = tot + b.tot;
		return ret;
	}

	node reverse() {
		node ret = *this;
		swap(ret.sufmax, ret.prefmax);
		swap(ret.sufmin, ret.prefmin);
		return ret;
	}
};


template<class T>
struct LCA {
	T ID;
	bool online = false;
	const int LEVELS = 19;
	vector<vector<int > > v;
	vector<int> depth;
	vector<T> a;
	vector<vector<pair<int, T> > > jump;
	vector<pair<int, int> > euler_tour;

	void getDepth(int x, int last) {
		if (last != -1) depth[x] = depth[last] + 1;
		for (int n : v[x]) {
			if (last == n) continue;
			getDepth(n, x);
		}
	}
	
	explicit LCA(vector<vector<int> > & _v, vector<T> & _a, T _ID = T()) : ID(_ID) {
		v = _v;
		a = _a;

		int n = v.size();
		depth.assign(n, 0);
		jump.resize(LEVELS);

		for (int i = 0; i < LEVELS; i++) {
			jump[i].assign(n, {-1, ID});
		}
		euler_tour.resize(n);
		getDepth(0, -1);

		int cnt = 0;
		// populate jump[i] with the 2^0th ancestor of i, and d with the euler

		function<void (int x, int & cnt, int last)> lca_dfs = [&](int x, int & cnt, int last) {
			jump[0][x] = {last, a[x]};
			int s = cnt;
			for (auto u : v[x]) {
				if (n == last) continue;
				lca_dfs(u, ++cnt, x);
			}
			int e = cnt;
			euler_tour[x] = {s, e};
		};

		lca_dfs(0, cnt, -1);

		for (int i = 1; i < jump.size(); i++) {
			for (int j = 0; j < n; j++) {
				auto old = jump[i - 1][j];
				if (old.first == -1) continue;
				auto next = jump[i - 1][old.first];
				jump[i][j] = {next.first, old.second + next.second};
			}
		}
	}

	void addEdge(int x, int y, T w) {
		online = true;
		if (y >= a.size()) {
			assert(y == a.size());
			a.push_back(w);
			v.push_back({x});
			depth.push_back(depth[x] + 1);
			for (int i = 0; i < jump.size(); i++) {
				jump[i].push_back({});
			}
		}
		a[y] = w;
		v[y] = {x};
		depth[y] = depth[x] + 1;
		v[x].push_back(y);
		jump[0][y] = {x, w};
		for (int i = 1; i < jump.size(); i++) {
			auto old = jump[i - 1][y];
			if (old.first == -1) continue;
			auto next = jump[i - 1][old.first];
			jump[i][y] = {next.first, old.second + next.second};
		}
	}

	// return if a is an ancestor of b. This runs in log(n)
	bool isAncestorOnline(int a, int b) {
		if (depth[b] < depth[a]) return false;
		return jmp(b, depth[b] - depth[a]).first == a;
	}

	// runs in constant time
	bool isAncestorOffline(int a, int b) {
		return (euler_tour[a].first <= euler_tour[b].first && euler_tour[a].second >= euler_tour[b].second);
	}

	// THIS IS LOG^2(n) if edges are added online and LOG(n) otherwise.
	T query(int x, int y) {
		int anc = lca(x, y);
		auto xa = jmp(x, depth[x] - depth[anc]).second + a[anc];
		auto xb = jmp(y, depth[y] - depth[anc]).second.reverse();
		return xa + xb;
	}

	bool isAncestor(int a, int b) {
		if (online) {
			return isAncestorOnline(a, b);
		}
		return isAncestorOffline(a, b);
	}

	// jumps to the dth ancestor of x
	// returns the ancestor with the answer on a segment (NOT INCLUDING LAST NODE)
	pair<int, T> jmp(int x, int d) {
		pair<int, T> ret = {x, ID};
		for (int i = 0; i < LEVELS; i++) {
			if ((1 << i) & d) {
				ret = {jump[i][x].first, ret.second + jump[i][x].second};
				x = ret.first;
			}
			if (x == -1) return {-1, ID};
		}
		return ret;
	}

	int lca(int a, int b) {
		int low = 0;
		int high = 1 << LEVELS;
		int best = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			auto anc = jmp(a, mid);
			if (anc.first == -1) {
				high = mid - 1;
				continue;
			}
			if (isAncestor(anc.first, b)) {
				high = mid - 1;
				best = anc.first;
			} else {
				low = mid + 1;
			}
		}
		return best;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<node> a = {{1, 1, 1, 0, 0, 0, 1}};
		vector<vector<int> > v(1);
		LCA<node> lca(v, a);
		int cur = 1;
		for (int i = 0; i < n; i++) {
			char t;
			cin >> t;
			if (t == '+') {
				int u, x;
				cin >> u >> x;
				u--;
				lca.addEdge(u, cur, {max(x, 0), max(x, 0), max(x, 0), min(x, 0), min(x, 0), min(x, 0), x});
				cur++;
			} else {
				int u, v, k;
				cin >> u >> v >> k;
				u--;
				v--;
				node res = lca.query(u, v);
				if (res.mini <= k && k <= res.maxi) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}			
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
