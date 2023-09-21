#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		map<int, vector<int> > m;
		set<int> col;
		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			m[c].push_back(i);
			col.insert(c);
		}
		for (auto c : col) {
			m[c].push_back(-1);
			m[c].push_back(n);
			sort(m[c].begin(), m[c].end());
		}
		int res = n;
		for (auto & x : m) {
			multiset<int> dist;
			for (int i = 1; i < x.second.size(); i++) {
				int d = x.second[i] - x.second[i - 1] - 1;
			//	cout << x.first << " " << i << " " << d << endl;
				if (d >= 0) dist.insert(d);
			}
			if (dist.empty()) {
				res = 0;
				break;
			}
			auto it = dist.rbegin();
			int v = *it;
			dist.erase(dist.find(v));
			dist.insert(v / 2);
			res = min(res, *dist.rbegin());
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
