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
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n);
		vector<long long> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		vector<array<long long, 3> > e;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
			e.push_back({max(h[x], h[y]), x, y});
		}
		sort(e.begin(), e.end());

		// 
		vector<vector<long long> > queries;
		int q;
		cin >> q;
		// 
		for (int i = 0; i < q; i++) {
			long long a, b, e;
			cin >> a >> b >> e;
			a--;
			b--;
			queries.push_back({a, b, e, i});
		}
		sort(queries.begin(), queries.end(), [&](const auto & l, const auto & r) {
			return h[l[0]] + l[2] < h[r[0]] + r[2];
		});

		DSU dsu(n);
		int ind = 0;
		vector<string> res(q);
		
		
		for (int i = 0; i < q; i++) {
			//cout << queries[i][0] << " " << queries[i][1] << " " << queries[i][2] << " " << queries[i][3] << " " << h[queries[i][0]] + queries[i][2] << endl;
			//cout << i << " " << q << " " << ind << " " << e.size() << endl;
			while (ind < e.size() && e[ind][0] <= h[queries[i][0]] + queries[i][2]) {
				//cout << ind << " " << e[ind][0] << endl;
				dsu.unite(e[ind][1], e[ind][2]);
				ind++;
			}
			
			if (dsu.same_set(queries[i][0], queries[i][1])) {
				res[queries[i][3]] = "YES";
			} else {
				res[queries[i][3]] = "NO";
			}
		}
		for (int i = 0; i < q; i++) {
			cout << res[i] << endl;
		}
		cout << endl;

		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
