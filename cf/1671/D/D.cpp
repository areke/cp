#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, x;
		cin >> n >> x;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long mini = *min_element(v.begin(), v.end());

		long long maxi = *max_element(v.begin(), v.end());
		long long res = 0;

		for (int i = 1; i < n; i++) {
			res += abs(v[i] - v[i - 1]);
		}
		if (x > maxi) {
			long long cur = min(abs(v[0] - x), abs(v[n - 1] - x));

			for (int i = 1; i < n - 1; i++) {
				cur = min(cur, 2 * abs(v[i] - x));
			}
			res += cur;
		}
		if (1 < mini) {
			long long cur = min(abs(v[0] - 1), abs(v[n - 1] - 1));
			for (int i = 0; i < n - 1; i++) {
				if (maxi >= v[i]) {
					cur = min(cur, 2 * abs(v[i] - 1));
				} else {
					cur = min(cur, abs(v[i] - 1) + abs(v[i + 1] - 1));
				}
			}
			res += cur;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
