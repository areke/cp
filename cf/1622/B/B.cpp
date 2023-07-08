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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}

		string s;
		cin >> s;
		vector<vector<pair<int, int > > > v(2);
		for (int i = 0; i < n; i++) {
			v[s[i] - '0'].push_back({p[i], i});
		}
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		vector<int> res(n, 0);
		int cur = 1;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j< v[i].size(); j++) {
				res[v[i][j].second] = cur++;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
