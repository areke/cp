#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<vector<long long> > v(n);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v[i].resize(x);
			for (int j = 0; j < x; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			sort(v[i].begin(), v[i].end());
		}
		long long s = 0;
		for (int i = 0; i < n; i++) {
			s += v[i][1];
		}
		long long mini = 2e9;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				mini = min(mini, v[i][j]);
			}
		}
		long long res = -1e18;
		for (int i = 0; i < n; i++) {
			long long cur = s - v[i][1] + mini;
			res = max(res, cur);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
