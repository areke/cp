#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k, g;
		cin >> n >> k >> g;
		if ((g / 2 - 1) * n >= k) {
			cout << k * g << endl;
		} else {
			long long low = 0;
			long long high = n;
			while (low <= high) {
				long long mid = (low + high) / 2;
				
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
