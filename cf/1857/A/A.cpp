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
		int s = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s += x;
		}
		if (s & 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
