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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> v(n);

		vector<set<int> > cnt(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v[i]--;
			cnt[i].insert(v[i]);
			cnt[v[i]].insert(i);
		}
		DSU dsu(n);
		for (int i = 0; i < n; i++) {
			dsu.unite(i, v[i]);
		}
		map<int, vector<int> > m;
		for (int i = 0; i < n; i++) {
			m[dsu.get(i)].push_back(i);
		}
		int a = 0;
		int b = 0;
		for (auto x : m) {
			bool can = false;
			for (int y : x.second) {
				if (cnt[y].size() < 2) can = true;
			}
			if (can) {
				b++;
			} else {
				a++;
			}
		}
		int mini = a;
		int maxi = a + b;
		if (b) mini++;
		cout << mini << " " << maxi << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
