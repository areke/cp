#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, b, x, y;
		cin >> n >> b >> x >> y;
		long long cur = 0;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (cur + x <= b) {
				cur += x;
			} else {
				cur -= y;
			}
			res += cur;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
