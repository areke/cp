#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int a[2][2];

		int cnt = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> a[i][j];
				cnt += a[i][j];
			}
		}
		if (cnt == 4) {
			cout << 2 << endl;
		} else if (cnt) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
