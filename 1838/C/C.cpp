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
		vector<vector<int> > v(n, vector<int>(m, 0));
		if (n % 2 == 0) {
			int cur = 1;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					v[j][i] = cur++;
				}
			}
		} else if (m % 2 == 0) {
			int cur = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					v[i][j] = cur++;
				}
			}
		} else {
			for (int i = 0; i < n / 2 + 1; i++) {
				for (int j = 0; j < m; j++) {
					v[i][j] = i * 2 * m + j + 1;
				}
			}
			for (int i = n / 2 + 1; i < n; i++) {
				for (int j = 0; j < m; j++) {
					v[i][j] = (i - n / 2 - 1) * 2 * m + m + 1 + j;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << v[i][j] << " \n"[j == m - 1];
			}
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
