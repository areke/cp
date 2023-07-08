#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long x;
		cin >> x;
		long long res = 0;
		int cnt = 0;
		for (int i = 0; i <= 31; i++) {
			if ((1 << i) & x) {
				cnt++;
			}
		}
		for (int i = 0; i <= 31; i++) {
			if ((1 << i) & x) {
				res |= (1 << i);
				break;
			}
		}
		if (cnt == 1) {
			for (int i = 0; i <= 31; i++) {
				if (!((1 << i) & x)) {
					res |= (1 << i);
					break;
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
