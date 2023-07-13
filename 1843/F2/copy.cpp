#include <bits/stdc++.h>
using namespace std;
 
struct node {
	int maxi, sufmax, prefmax;
	int mini, sufmin, prefmin;
	int tot;
};
 
 
template<class T>
struct LCA {
 
	T ID = {0, 0, 0, 0, 0, 0, 0};
	int n;
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
 
	T comb(T a, T b) {
		node ret;
		ret.maxi = max(max(a.maxi, b.maxi), a.sufmax + b.prefmax);
		ret.sufmax = max(b.sufmax, b.tot + a.sufmax);
		ret.prefmax = max(a.prefmax, a.tot + b.prefmax); 
 
		ret.mini = min(min(a.mini, b.mini), a.sufmin + b.prefmin);
		ret.sufmin = min(b.sufmin, b.tot + a.sufmin);
		ret.prefmin = min(a.prefmin, a.tot + b.prefmin); 
		ret.tot = a.tot + b.tot;
		return ret;
	}
 
	T rev(T a) {
		node ret = a;
		swap(ret.sufmax, ret.prefmax);
		swap(ret.sufmin, ret.prefmin);
		return ret;
	}
	
	void addEdge(int x, int y, T w) {
		assert(y == a.size());
		a.push_back({});
		v.push_back({});
		depth.push_back(0);
		for (int i = 0; i < jump.size(); i++) {
			jump[i].push_back({});
		}
 
		depth[y] = depth[x] + 1;
		a[y] = w;
		v[y].push_back(x);
		v[x].push_back(y);
		jump[0][y] = {x, w};
		for (int i = 1; i < jump.size(); i++) {
			auto old = jump[i - 1][y];
			if (old.first == -1) continue;
			auto next = jump[i - 1][old.first];
			jump[i][y] = {next.first, comb(old.second, next.second)};
		}
	}
 
	bool query(int x, int y, int k) {
		int anc = lca(x, y);
		auto xa = jmp(x, depth[x] - depth[anc]).second;
		auto xc = comb(xa, rev(a[anc]));
		auto xb = rev(jmp(y, depth[y] - depth[anc]).second);
		auto t = comb(xc, xb);
		//cout << x << " " << y << " " << anc << " " << a[x].mini << " " << xa.mini << endl;
	//	cout << x << " " << y << " " << anc << " " << xa.mini << " " << depth[x] - depth[anc] << " " << xb.mini << endl;
		return k >= t.mini && k <= t.maxi;
	}
 
	
	LCA(vector<vector<int> > & v, vector<T> & a) {
		this->v = v;
		this->n = v.size();
		this->a = a;
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
				if (old.first == -1) continue;
				auto next = jump[i - 1][old.first];
				jump[i][j] = {next.first, comb(old.second, next.second)};
			}
		}
	}
	// given a vector<pair<int, int> > of the start and exit of the euler tour of d
	// return if a is an ancestor of b
	bool isAncestor(int a, int b) {
		if (depth[b] < depth[a]) return false;
		return jmp(b, depth[b] - depth[a]).first == a;
	}
 
 
	// jumps to the dth ancestor of x
	// returns the ancestor with the answer on a segment (NOT INCLUDING LAST NODE)
	pair<int, T> jmp(int x, int d) {
		pair<int, T> ret = {x, ID};
		for (int i = 0; i < LEVELS; i++) {
			if ((1 << i) & d) {
				ret = {jump[i][x].first, comb(ret.second, jump[i][x].second)};
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
	int tc = 0;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<node> a = {{1, 1, 1, 0, 0, 0, 1}};
		vector<vector<int> > v(1);
		LCA<node> lca(v, a);
		int cur = 1;
		vector<pair<char, vector<int> > > ct;
		bool found = false;
		for (int i = 0; i < n; i++) {
			char t;
			cin >> t;
			pair<char, vector<int> > curt;
			curt.first = t;
 
			if (t == '+') {
				int u, x;
				cin >> u >> x;
				u--;
				lca.addEdge(u, cur, {max(x, 0), max(x, 0), max(x, 0), min(x, 0), min(x, 0), min(x, 0), x});
				curt.second = {u + 1, x};
				cur++;
				
			} else {
				tc++;
 
				int u, v;
				cin >> u >> v;
				u--;
				v--;
 
				int k;
				cin >> k;
				if (lca.query(u, v, k)) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
				curt.second = {u + 1, v + 1, k};
			}
			ct.push_back(curt);
			
		}
		
 
 
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}