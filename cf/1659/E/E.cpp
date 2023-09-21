#include <bits/stdc++.h>
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
	vector<DSU> z(30, DSU(n));
	vector<DSU> o(30, DSU(n));
	vector<bool> e(n, 0);


	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		for (int j = 0; j < 30; j++) {
			if ((w >> j) & 1) {
				z[j].unite(a, b);
			}
		}
		if (w & 1) {
			for (int j = 1; j < 30; j++) {
				if ((w >> j) & 1) {
					o[j].unite(a, b);
				}
			}
		} else {
			e[a] = 1;
			e[b] = 1;
		}
	}
	vector<map<int, bool> > om(30);
	for (int i = 1; i < 30; i++) {
		for (int j = 0; j < n; j++) {
			if (e[j]) {
				om[i][o[i].get(j)] = true;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		bool zero = false;
		for (int i = 0; i < 30; i++) {
			if (z[i].same_set(a, b)) {
				zero = true;
				break;
			}
		}
		if (zero) {
			cout << 0 << endl;
			continue;
		}
		bool one = false;
		for (int i = 1; i < 30; i++) {
			if (om[i][o[i].get(a)]) {
				one = true;
				break;
			}
		}
		if (one) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
