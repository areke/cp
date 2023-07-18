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

		vector<vector<int> > res(n, vector<int>(m, 0));
		
		pair<int, int> pass = {-1, -1};
		
		
		auto check = [&](bool fx, bool fy) {
			vector<vector<int> > r(n, vector<int>(m, 0));
			pair<int, int> t = {-1, -1};
			for (int jj = m - 1; jj >= 0; jj--) {
				int j = jj;
				if (fx) j = m - jj - 1;
				for (int ii = 0; ii < n; ii++) {
					int i = ii;
					if (fy) i = n - i - 1;
					if (t != pass) {
						res[i][j] = max(res[i][j], abs(t.first - ii) + abs(t.second - jj));
					}
					if (v[i][j] == 'B') {
						if (t == pass || n - t.first + t.second < n - ii + jj) {
							t = {ii, jj};
						}
					}
				}
			}
		};
		auto maxi = [&](vector<vector<int> > & a) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					res[i][j] = max(res[i][j], a[i][j]);
				}
			}
		};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				check(i, j);
			}
		}

		pair<int, int> ans = {0, 0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << res[i][j] << " ";
				if (res[i][j] < res[ans.first][ans.second]) {
					ans = {i, j};
				}
			}
			//cout << endl;
		}
		cout << ans.first + 1 << " " << ans.second + 1 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
