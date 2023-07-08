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
		vector<pair<long long, long long> > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].second >> v[i].first;
		}
		sort(v.begin(), v.end());
		map<long long, int> m;
		long long res = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (m[v[i].second] < v[i].second) {
				m[v[i].second]++;
				res += v[i].first;
			}
		}
		cout << res << endl;

		

		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
