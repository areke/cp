#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	long double res = 0;
	for (int x = 1; x <= k; x++) {
		long double a = 1;
		long double b = 1;
		for (int j = 0; j < n; j++) {
			a *= ((long double) x) / (long double)(k);
			b *= ((long double) x - 1) / (long double)(k);
		}
		res += (a - b) * (long double)(x);
	}
	cout << fixed << setprecision(6) << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
