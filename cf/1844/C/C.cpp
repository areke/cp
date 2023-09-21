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
		vector<long long> l(n, -1e18);
		vector<long long> r(n, -1e18);
		l[0] = v[0];
		for (int i = 1; i < n; i++) {
			l[i] = max(l[i], v[i]);
			if (i >= 2) {
				l[i] = max(l[i - 2] + v[i], l[i]);
				l[i] = max(l[i - 2], l[i]);
			}
		}
		r[n - 1] = v[n - 1];
		for (int i = 1; i < n; i++) {
			r[n - i - 1] = max(r[n - i - 1], v[n - i - 1]);
			if (i >= 2) {
				r[n - i - 1] = max(r[n - i - 1 + 2] + v[n - i - 1], r[n - i - 1]);
				r[n - i - 1] = max(r[n - i - 1 + 2], r[n - i + 1]);
			}
		}
		long long res = -1e18;
		for (int i = 0; i < n; i++) {
			res = max(res, l[i]);
			res = max(res, r[i]);
		}
		for (int i = 1; i < n - 1; i++) {
			res = max(res, l[i - 1] + r[i + 1]);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
