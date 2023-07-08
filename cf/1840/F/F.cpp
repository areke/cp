#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > dirs = {{0, 0}, {0, 1}, {1, 0}};

int n, m, r;

int ind(int x, int y) {
	return x * (m + 1) + y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1;  test <= tests; test++) {
		
		cin >> n >> m >> r;
		map<int, vector<pair<int, int> > > mp;
		for (int i = 0; i < r; i++) {
			int t, d, c;
			cin >> t >> d >> c;
			mp[t].push_back({d, c});
		}
		vector<int> dp((n + 1) * (m + 1), 0);

		vector<int> ndp((n + 1) * (m + 1), 0);
		dp[0] = 1;
		int res = -1;
		for (int i = 1; i <= n + m + r + 1; i++) {
			fill(ndp.begin(), ndp.end(), 0);
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= m; k++) {
					if (!dp[ind(j, k)]) continue;
					for (auto & d : dirs) {
						if (j + d[0] < 0 || j + d[0] > n) continue;
						if (k + d[1] < 0 || k + d[1] > m) continue;
						ndp[ind(j + d[0], k + d[1])] = 1;
					}
				}
			}
			for (auto it : mp[i]) {
				if (it.first == 1) {
					for (int j = 0; j <= m; j++) {
						ndp[ind(it.second, j)] = 0;
					}
				} else {
					for (int j = 0; j <= n; j++) {
						ndp[ind(j, it.second)] = 0;
					}
				}
			}
			swap(dp, ndp);
			if (dp[ind(n, m)]) {
				res = i;
				break;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
