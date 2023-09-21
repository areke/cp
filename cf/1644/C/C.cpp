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
		long long x;
		cin >> x;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> v(n + 1, -1e18);
		v[0] = 0;
		for (int i = 0; i < n; i++) {
			long long s = 0;
			for (int j = i; j < n; j++) {
				s += a[j];
				v[j - i + 1] = max(v[j - i + 1], s);
			}
		}

		vector<long long> m(n + 1, 0);
		m[n] = v[n];
		for (int i = n - 1; i >= 0; i--) {
			m[i] = max(v[i], m[i + 1]);
		}
		for (int i = 0; i <= n; i++) {
			v[i] += x * i;
		}
		vector<long long> res(n + 1, 0);
		res[0] = m[0];
		for (int i = 1; i <= n; i++) {
			res[i] = max(m[i] + x * i, v[i]);
			res[i] = max(res[i], res[i - 1]);
		}
		for (int i = 0; i <= n; i++) {
			cout << res[i] << " \n"[i == n];
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
