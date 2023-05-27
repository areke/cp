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
			if (i >= 1)  {
				s ^= (i % 2);
			}
		}
		if (s) {
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
