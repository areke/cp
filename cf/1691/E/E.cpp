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
		vector<pair<set<int>, set<int> > > s(2);
		vector<vector<int> > v;
		for (int i = 1; i <= n; i++) {
			vector<int> x(3);
			cin >> x[0] >> x[1] >> x[2];
			v.push_back({x[1], i, x[0]});
			v.push_back({x[2] + 1, -i, x[0]});
		}
		DSU dsu(n);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			//cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " << s[0].size() << " " << s[1].size() << endl;

			if (v[i][1] > 0) {
				for (int x : s[v[i][2] ^ 1].second) {
					dsu.unite(x - 1, v[i][1] - 1);
					//cout << x << " " << v[i][1] << endl;
				}
				for (int x : s[v[i][2] ^ 1].first) {
					dsu.unite(x - 1, v[i][1] - 1);
					break;
				}
				s[v[i][2] ^ 1].first.insert(s[v[i][2] ^ 1].second.begin(), s[v[i][2] ^ 1].second.end());
				s[v[i][2] ^ 1].second.clear();
				s[v[i][2]].second.insert(v[i][1]);
			} else {
				s[v[i][2]].first.erase(abs(v[i][1]));
				s[v[i][2]].second.erase(abs(v[i][1]));
			}
		}
		set<int> res;
		for (int i = 0; i < n; i++) {
			res.insert(dsu.get(i));
		}
		cout << res.size() << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
