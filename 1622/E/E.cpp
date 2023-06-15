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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		long long best = -1e18;
		vector<int> res;
		for (int i = 0; i < (1 << n); i++) {
			vector<pair<int, int> > p;
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (((i >> k) & 1) && (s[k][j] - '0')) {
						cnt++;
					}
					if (!((i >> k) & 1) && !(s[k][j] - '0')) {
						cnt--;
					}
				}
				p.push_back({cnt, j});
				
			}
			sort(p.begin(), p.end());

			vector<long long> scores(n, 0);
			vector<int> cur(m);
			for (int j = 0; j < m; j++) {
				cur[p[j].second] = j + 1;
				for (int k = 0; k < n; k++) {
					if (s[k][p[j].second] - '0') {
						scores[k] += j + 1;
					}
				}
			}
			long long x = 0;
			for (int j = 0; j < n; j++) {
				x += abs(scores[j] - v[j]);
			}
			if (x > best) {
				best = x;
				res = cur;
			}
		}
		for (int i = 0; i < m; i++) {
			cout << res[i] << " \n"[i == m - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
