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
		vector<pair<int, int> > v;
		DSU dsu(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		string res = "";
		set<int> bad;
		for (int i = 0; i < v.size(); i++) {
			pair<int, int> it = v[i];
			if (dsu.same_set(it.first, it.second)) {
				bad.insert(i);
			} else {
				dsu.unite(it.first, it.second);
			}
		}
		int sw = -1;
		DSU dsu2(n + 1);
		for (int i : bad) {
			if (dsu2.same_set(v[i].first, v[i].second)) {
				sw = i;
			} else {
				dsu2.unite(v[i].first, v[i].second);
			}
		}
		if (sw != -1) {
			DSU dsu3(n + 1);
			dsu3.unite(v[sw].first, v[sw].second);
			for (int i = 0; i < v.size(); i++) {
				if (bad.find(i) == bad.end()) {
					if (dsu3.same_set(v[i].first, v[i].second)) {
						bad.insert(i);
					} else {
						dsu3.unite(v[i].first, v[i].second);
					}
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (bad.find(i) != bad.end() && i != sw) {
				res += '0';
			} else {
				res += '1';
			}
		}


		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
