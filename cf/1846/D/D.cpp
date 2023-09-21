#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, d, h;
		cin >> n >> d >> h;
		long double l = -1e6;
		long double res = 0;
		for (int i = 0; i < n; i++) {
			long double y;
			cin >> y;
			res += (long double)d * h / 2;
			if (l + h > y) {
				long double nh = (h - (y - l));
				long double nd = (nh / h) * d;
				res -= nh * nd / 2;
			}
			l = y;
		}
		cout << fixed << setprecision(8) << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
