#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		map<int, int> m;
		for (int i = 1; i <= 5e5; i++) {
			m[i] = i;
		}
		vector<vector<int> > v;
		for (int i = 0; i < n; i++) {
			int q, x;
			cin >> q >> x;
			if (q == 2) {
				int y;
				cin >> y;
				v.push_back({q, x, y});
			} else {
				v.push_back({q, x});
			}
		}
		vector<int> res;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i][0] == 1) {
				res.push_back(m[v[i][1]]);
			} else {
				int x = v[i][1];
				int y = v[i][2];
				m[x] = m[y];
			}
		}
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " \n"[i == res.size() - 1];
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
