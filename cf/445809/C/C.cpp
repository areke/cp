#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long x, y;
		cin >> x >> y;
		if (x > y) {
			cout << x + y << "\n";
		} else if (x == y) {
			cout << y << "\n";
		} else {
			for (long long i = 1; i * i <= x + y; i++) {
				long long a = (x + y) / i;
				if (a * i == (x + y)) {
					if (i % x == y % i) {
						cout << i << "\n";
						break;
					}
					if (a % x == y % a) {
						cout << a << "\n";
						break;
					}
				}
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
