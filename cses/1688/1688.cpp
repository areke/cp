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

// SOLVES https://cses.fi/problemset/task/1688

const int LEVELS = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> p(n, -1);
	vector<vector<int > > v(n);
	
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
    // 0 is the edge weight
		v[p[i]].push_back({i});
		v[i].push_back({p[i]});
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

	// given a vector<pair<int, int> > of the start and exit of the euler tour of d
	// return if a is an ancestor of b
	auto isAncestor = [&](int a, int b) {
		return (d[a].first <= d[b].first && d[a].second >= d[b].second);
	};

	// jumps to the dth ancestor of x
	// returns the ancestor and the max edge 
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

	// return lca of a and b and distance from a to the lca
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
				best = anc;
			} else {
				low = mid + 1;
			}
		}

		return best;
	};
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << lca(a, b) + 1 << "\n";
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
