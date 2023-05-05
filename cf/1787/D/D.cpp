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
long long n;
bool dfs(int x, vector<int> & v, vector<bool> & vis, vector<int> & p, vector<bool> & cycles) {
	if (x < 0 || x >= n) return false;
	if (vis[x]) return cycles[x];
	vis[x] = true;
	p.push_back(x);
	return cycles[x] = dfs(v[x], v, vis, p, cycles);
}

int dfs2(int x, vector<vector<int> > & r, int cur, vector<int> & depth) {
	if (depth[x]) return depth[x];
	int s = 1;
	for (int n : r[x]) {
		s += dfs2(n, r, cur + 1, depth);
	}
	return depth[x] = s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// find cycles
		// 1 is part of a cycle, you can change any part of the cycle to 
		// a number that is part of a winning path, or the end.
		// if 1 is not part of a cycle, you can change anything not part of 1 to anything.
		// you can change anything part of 1 to go to a different winning path, or the end.
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			v[i] = i + a[i];
		}
		vector<bool> vis(n, false);
		vector<vector<int> > paths;
		vector<bool> cycles;
		vector<bool> c(n, true);
		int comp = 1;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				vector<int> p;
				bool cycle = dfs(i, v, vis, p, c);
				paths.push_back(p);
				cycles.push_back(cycle);
			}
		}
		long long res = 0;
		if (!cycles[0]) {
			res += (2 * n + 1) * (n - paths[0].size());
		}
		// 7 + wins = 3
		// 4 + 4 +7 = 15 + 3 * 2 = 21
		long long wins = 0;
		set<int> first;
		
		vector<vector<int> > r(n);
		for (int i = 0; i< n; i++) {
			if (v[i] >= 0 && v[i] < n) {
				r[v[i]].push_back(i);
			}
		}
		vector<int> depth(n, 0);
		if (!cycles[0]) {
			dfs2(paths[0][paths[0].size() - 1], r, 1, depth);
		}
		for (int i = 0; i < n; i++) {
			if (!c[i]) wins++;
		}
		int bad = 0;

		//cout << wins << endl;
		for (int i = 0; i < paths[0].size(); i++) {
			res += (n + 1);
			res += wins;
			res -= depth[paths[0][i]];
		}
		cout << res << endl;
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
