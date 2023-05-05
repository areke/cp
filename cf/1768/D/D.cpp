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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}
		set<int> s;
		DSU dsu(n);
		for (int i = 0; i < n; i++) {
			dsu.unite(i, p[i]);
		}
		int ans = 0;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			m[dsu.get(i)] = dsu.size(i);
		}
		int res = 1e8;
		for (auto it : m) {
			ans += it.second - 1;
		}

		// try all adjacent
		// if adjacent are in different components:
			// if one has size 1, answer
			// if both have size 1, answer + 1
			// if both greater than 1, answer - 1
		// if adjacent are in the same component:
			// edge between the two, answer - 1
			// else answer
		for (int i = 0; i < n - 1; i++) {
			if (!dsu.same_set(i, i + 1)) {
				res = min(res, ans + 1);
			} else {
				res = min(res, ans - 1);
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
