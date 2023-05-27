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
		int x = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			x ^= (a % 4);
		}
		if (x) {
			cout << "first" << endl;
		} else {
			cout << "second" << endl;
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
