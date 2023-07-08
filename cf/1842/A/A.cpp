#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		long long a = 0;
		long long b = 0;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			a += x;
		}
		for (int i = 0; i< m; i++) {
			long long x;
			cin >> x;
			b += x;
		}
		if (a > b) {
			cout << "Tsondu" << endl;
		} else if (a == b) {
			cout << "Draw" << endl;
		} else {
			cout << "Tenzing" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
