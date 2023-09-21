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
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long low = 0;
		long long high = 1e18;
		long long best = 0;
		// 1 2
		// 
		while (low <= high) {
			long long mid = (low + high) / 2;
			long long cur = mid;
			for (int i = n - 1; i >= 0; i--) {
				if (cur < v[i]) continue;
				long long val = (cur - v[i]) / (i + 1);
				//cout << i << " "  << cur << " " << v[i] << " " << val << endl;
				
				cur -= min(k, val + 1);
			}
			//cout << cur << endl;
			if (cur > 0) {
				high = mid - 1;
			} else {
				best = mid;
				low = mid + 1;
			}
		}
		cout << best + 1 << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
