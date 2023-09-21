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
		vector<vector<int> > v;
		map<int, int> m;
		map<int, int> e;
		for (int i = 0; i < n; i++) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			v.push_back({l, 0, i});
			v.push_back({b, 2, i});
			e[i] = b;	
		}
		int q;
		cin >> q;

		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			v.push_back({x, 1, i});
		}
		sort(v.begin(), v.end());
		multiset<int> cur;
		vector<int> res(q, 0);
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i][1] == 0) {
				cur.erase(cur.find(m[v[i][2]]));
			} else if (v[i][1] == 1) {
				res[v[i][2]] = v[i][0];
				if (!cur.empty()) {
					res[v[i][2]] = max(res[v[i][2]], *cur.rbegin());
				}
			} else {
				m[v[i][2]] = v[i][0];
				if (!cur.empty()) {
					m[v[i][2]] = max(m[v[i][2]], *cur.rbegin());
				}
				cur.insert(m[v[i][2]]);
			}
		}
		for (int i = 0; i < q; i++) {
			cout << res[i] << " \n"[i == q - 1];
		}




	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
