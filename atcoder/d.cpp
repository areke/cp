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
	int n, m;
	cin >> n >> m;
	DSU dsu(n + 1);
	map<int, int> e;
	for (int i = 0; i < m; i++) {
		int a, c;
		char b, d;
		cin >> a >> b >> c >> d;
		dsu.unite(a, c);
		e[a]++;
	}
	map<int, int> comp;
	set<int> comps;
	for (int i = 1; i <= n; i++) {
		comp[dsu.get(i)] += e[i];
		comps.insert(dsu.get(i));
	}
	int res1 = 0;
	int res2 = 0;
	for (int x : comps) {
		if (comp[x] == dsu.size(x)) {
			res1++;
		} else {
			res2++;
		}
	}
	cout << res1 << " " << res2 << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
