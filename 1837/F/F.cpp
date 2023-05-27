#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long low = 0;
		long long high = 1e15;
		long long best = 1e15;
		while (low <= high) {
			long long mid = (low + high) / 2;
			long long s = 0;

			priority_queue<long long> a;
			long long as = 0;
			vector<int> c(n, 0);
			for (int i = 0; i < n; i++) {
				a.push(v[i]);
				s += v[i];
				while (s > mid) {
					s -= a.top();
					a.pop();
				}
				c[i] = a.size();
			}
			a = {};
			s = 0;
			for (int i = 0; i < n - 1; i++) {
				a.push(v[n - i - 1]);
				s += v[n - i - 1];
				while (s > mid) {
					s -= a.top();
					a.pop();
				}
				c[n - i - 2] += a.size();
			}
			int maxi = 0;
			for (int i = 0; i < n; i++) {
				maxi = max(maxi, c[i]);
			}
			if (maxi >= k) {
				high = mid - 1;
				best = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
