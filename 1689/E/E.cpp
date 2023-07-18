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
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				v[i]++;
				res++;
			} 
		}

		auto check = [&]() {
			DSU dsu(30);
			vector<bool> used(30, 0);
			for (int i = 0; i < n; i++) {
				if (!v[i]) return false;
				int last = -1;
				for (int j = 0; j < 30; j++) {
					if ((v[i] >> j) & 1) {
						used[j] = 1;
						if (last != -1) dsu.unite(j, last);
						last = j;
					}
				}
			}
			set<int> c;
			for (int i = 0; i < 30; i++) {
				if (used[i]) c.insert(dsu.get(i));
			}
			if (c.size() == 1) {
				cout << res << endl;
				for (int i = 0; i < n; i++) {
					cout << v[i] << " \n"[i == n - 1];
				}
			}
			return c.size() == 1;
		};
		if (check()) continue;
		bool found = false;
		for (int i = 0; i < n; i++) {
			res++;
			v[i]++;
			if (check()) {
				found = true;
				break;
			}
			v[i] -= 2;
			if (check()) {
				found = true;
				break;
			}
			res--;
			v[i]++;
		}
		if (found) continue;
		int b = 0;
		for (int i = 0; i < n; i++) {
			b = max(b, v[i] & (-v[i]));
		}
		vector<int> l;
		for (int i = 0; i < n; i++) {
			if ((v[i] & (-v[i])) == b) {
				l.push_back(i);
			}
		}
		assert(l.size() >= 2);
		v[l[0]]++;
		v[l[1]]--;
		res += 2;
		cout << res << endl;
		for (int i = 0; i < n; i++) {
			cout << v[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}