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
		string res = "YES";
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				int cnt = 0;
				for (int k= 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						cnt += v[i + k][j + l] - '0';
					}
				}
				if (cnt == 3) {
					res = "NO";
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
