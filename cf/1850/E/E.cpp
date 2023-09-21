#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		long long c;
		cin >> n >> c;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long low = 0;
		long long high = 1e9;
		long long res = -1;
		while (low <= high) {
			long long mid = (low + high) / 2;
			long long cur = 0;
			for (int i = 0; i < n; i++) {
				cur += (2 * mid + v[i]) * (2 * mid + v[i]);
				if (cur > c) {
					break;
				}
			}
			if (cur > c) {
				high = mid - 1;
			} else if (cur < c) {
				low = mid + 1;
			} else {
				res = mid;
				break;
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
