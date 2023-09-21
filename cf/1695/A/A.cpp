#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int a, b;
		cin >> a >> b;
		int x, y;
		int maxi = -2e9;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int v;
				cin >> v;
				if (v > maxi) {
					x = i;
					y = j;
					maxi = v;
				}
			}
		}
		int x1 = max(x + 1, a - x);
		int x2 = max(y + 1, b - y);
		cout << x1 * x2 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
