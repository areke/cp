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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<array<long long, 3> > v;
	for (int i = 0; i < m; i++) {
		int x, y;
		long long w;
		cin >> x >> y >> w;
		x--;
		y--;
		v.push_back({w, x, y});
	}
	sort(v.begin(), v.end());
	DSU dsu(n);
	long long res = 0;
	for (auto it : v) {
		if (!dsu.same_set(it[1], it[2])) {
			dsu.unite(it[1], it[2]);
			res += it[0];
		}
	}
	bool can = true;
	for (int i = 0; i < n; i++) {
		if (!dsu.same_set(i, 0)) {
			can = false;
		}
	}
	if (can) cout << res << endl;
	else cout << "IMPOSSIBLE" << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
