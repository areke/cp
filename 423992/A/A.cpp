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
			cin >> v[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i].second;
		}
		sort(v.begin(), v.end());
		long long s = 0;
		long long t = 0;
		long long mini = 1e18;
		for (int i = 0; i < n; i++) {
			mini = min(mini, v[i].first);
			if (v[i].second > 0) {
				s += v[i].first;
				t++;
			}
		}
		long long res = -1e18;
		if (t) res = max(res, s * t);
		else {
			cout << -mini << endl;
			continue;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (v[i].second < 0) {
				s += v[i].first;
				t--;
				res = max(res, s * t);
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
