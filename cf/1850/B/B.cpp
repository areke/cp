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
		int res = 1;
		int cur = -1;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			if (a <= 10 && b > cur) {
				cur = b;
				res = i;
			}
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
