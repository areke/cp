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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long low = 0;
		long long high = 1e9;
		long long best = 1;
		while (low <= high) {
			long long mid = (low + high) / 2;
			vector<long long> c = v;
			for (int i = n - 1; i >= 2; i--) {
				long long mov = min(v[i] / 3, (c[i] - mid)/ 3);
				if (mov > 0) {
					c[i - 1] += mov;
					c[i - 2] += 2 * mov;
				}
			}
			bool b = true;
			for (int i = n - 1; i >= 0; i--) {
				if (c[i] < mid) b = false;
			}
			if (b) {
				best = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
