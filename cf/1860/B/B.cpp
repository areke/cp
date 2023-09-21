#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long m, k, a, b;
		cin >> m >> k >> a >> b;
		long long x = m / k;
		int sub = min(x, b);
		m -= min(x, b) * k;
		b -= sub;
		if (m >= k) {
			if (a >= m % k) {
				a -= (m % k);
				m -= m % k;
			}
			
			long long y = m / k;
			long long z = a / k;
			sub = min(y, z);
			m -= min(y, z) * k;
			a -= sub * k;
			long long res = m / k + max((m % k) - a, 0LL);
			cout << res << endl;



		} else {
			m -= a;
			cout << max(0LL, m) << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
