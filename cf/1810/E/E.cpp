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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<pair<int, pair<int, int> > > v(m);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[i] = {max(a[x], a[y]), {x, y}};
		}
		sort(v.begin(), v.end());
		DSU dsu(n);
		int ind = 0;
		vector<bool> can(n, false);

		int best = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				can[i] = true;
				best = 1;
			}
		}
		for (int i = 0; i <= n; i++) {
			if (best < i) break;
			while (ind < m && v[ind].first <= i) {
				int aa = dsu.get(v[ind].second.first);
				int b = dsu.get(v[ind].second.second);
				bool c = false;
				if ((can[aa] && dsu.size(aa) >= v[ind].first) || (can[b] && dsu.size(b) >= v[ind].first)) {
					c = true;
				}
				dsu.unite(v[ind].second.first, v[ind].second.second);
				int nc = dsu.get(v[ind].second.first);
				assert(nc == aa || nc == b);
				can[nc] = c;
				if (can[nc]) {
					best = max(best, dsu.size(nc));
				}
				ind++;
			}
		}
		if (best == n) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
