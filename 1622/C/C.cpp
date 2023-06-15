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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long low = 0;
		long long high = 1e15;
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + a[i];
		}
		long long res = 1e15;
		while (low <= high) {
			long long mid = (low + high) / 2;

			long long best = 1e15;
			for (long long i = 0; i <= min(n - 1, mid); i++) {
				long long first = a[0] - (mid - i);
				long long dif = (p[n] - p[n - i]) - i * first; 
				long long tot = p[n] - ((a[0] - first) + dif);
				best = min(best, tot);
			}
			if (best <= k) {
				res = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
