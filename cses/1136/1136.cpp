#include <bits/stdc++.h>
using namespace std;
 
int solve(int x, vector<vector<int> > & v, vector<int> & a, vector<int> & b, int last) {
	int res = a[x];
	for (int n : v[x]) {
		if (n == last) continue;
		res += solve(n, v, a, b, x);
	}
	return b[x] = res;
}

void getDepth(int x, vector<vector<int> > & v, vector<int> & depth, int last) {
	if (last != -1) depth[x] = depth[last] + 1;
	for (int n : v[x]) {
		if (last == n) continue;
		getDepth(n, v, depth, x);
	}
}

const int LEVELS = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}


	vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
		
	vector<pair<int, int> > d(n);
	int cnt = 0;
	// populate jump[i] with the 2^0th ancestor of i, and d with the euler

	function<void (int x, int & cnt, int last)> dfs = [&](int x, int & cnt, int last) {
		jump[0][x] = last;
		int s = cnt;
		for (auto n : v[x]) {
			if (n == last) continue;
			dfs(n, ++cnt, x);
		}
		int e = cnt;
		d[x] = {s, e};
	};



	dfs(0, cnt, -1);

	for (int i = 1; i < jump.size(); i++) {
		for (int j = 0; j < n; j++) {
			auto old = jump[i - 1][j];
			if (old == -1) continue;
			auto next = jump[i - 1][old];
			jump[i][j] = next;
		}
	}
	vector<int> depth(n, 0);
	getDepth(0, v, depth, -1);

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
		if (depth[a] > depth[b]) swap(a, b);
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
	};
	vector<int> a(n, 0);
	vector<int> b(n, 0);
	vector<int> res(n, 0);
	

	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		a[x]++;
		a[y]++;
		int l = lca(x, y);
		a[l] -= 2;
		res[l]++;
	}
	solve(0, v, a, b, -1);
	for (int i = 0; i < n; i++) {
		res[i] += b[i];
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}


 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}