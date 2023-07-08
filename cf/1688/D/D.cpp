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
		vector<long long> p(n + 1, 0);
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + a[i];
		}
		long long res = 0;
		if (n <= k) {
			for (int i = 0; i < n; i++) {
				res += a[i];
			}
			res += n * (k - 1);
			res -= (n - 1) * n / 2;
		} else {
			for (int i = k; i <= n; i++) {
				//cout << p[i] << " " << p[i - k] << endl;
				res = max(res, (k - 1) * k / 2 + p[i] - p[i - k]);
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
