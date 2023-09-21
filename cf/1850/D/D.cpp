#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<int> good(n, 0);
		for (int i = 1; i < n; i++) {
			if (abs(v[i] - v[i - 1]) <= k) good[i] = 1;
		}
		int res = 0;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (good[i]) {
				cur++;
			} else {
				res = max(res, cur);
				cur = 0;
			}
		}
		res = max(res, cur);
		cout << n - (res + 1) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
