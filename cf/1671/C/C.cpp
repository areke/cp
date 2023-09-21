#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		long long x;
		cin >> n >> x;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + v[i];
		}
		long long res = 0;
		long long cur = -1;
		for (int i = n; i >= 1; i--) {
			long long low = cur + 1;
			long long high = 1e9;
			long long best = cur;
			while (low <= high) {
				long long mid = (low + high) / 2;
				if (mid * i + p[i] <= x) {
					low = mid + 1;
					best = mid;
				} else {
					high = mid - 1;
				}
			}
			res += (best - cur) * i;
			cur = best;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
