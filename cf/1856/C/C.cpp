#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k;
		cin >> n >> k;
		vector<long long> v(n);

		long long res = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			res = max(res, v[i]);
		}
		for (int i = 0; i < n; i++) {
			long long low = 0;
			long long high = 1e18;
			long long best = 0;
			while (low <= high) {
				long long mid = (low + high) / 2;
				long long cur = 0;
				bool can = false;
				for (int j = 0; j + i < n; j++) {
					long long need = v[i] + mid - j - v[i + j];
					if (need <= 0) {
						can = true;
						break;
					}
					cur += need;
				}
				if (can && cur <= k) {
					best = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			res = max(res, v[i] + best);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
