#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<vector<bool> > vis(n, vector<bool>(m, 0));
		vector<vector<int> > res;
		if (v[0][0] == '1') {
			cout << -1 << endl;
			continue;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (v[i][j] == '0') {
					res.push_back({i, j, i, j});
				} else {
					if (i > 0) {
						res.push_back({i - 1, j, i , j});
					} else if (j > 0) {
						res.push_back({i, j - 1, i, j});
					}
				}
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i][0] + 1 << " " << res[i][1] + 1 << " " << res[i][2] + 1 << " " << res[i][3] + 1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
