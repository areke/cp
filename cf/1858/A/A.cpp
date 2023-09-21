#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long x = a + c / 2;
		long long y = b + c / 2;
		if (c & 1) x++;
		if (x > y) {
			cout << "First" << endl;
		} else {
			cout << "Second" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
