#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	
	for (int test = 1; test <= tests; test++) {
		int x, y;
		cin >> x >> y;
		int s = sqrt(x * x + y * y);
		if (x == 0 && y == 0) {
			cout << 0 << endl;
		} else  if (s * s == (x * x + y * y)) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
