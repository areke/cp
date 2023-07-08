#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k, x;
		cin >> n >> k >> x;
		if (x == 1) {
			if (n == 1 || k == 1) {
				cout << "NO" << endl;
			} else if (k == 2) {
				if (n & 1) {
					cout << "NO" << endl;
				} else {
					cout << "YES" << endl;
					cout << n / 2 << endl;
					for (int i = 0; i < n / 2; i++) {
						cout << 2 << " \n"[i == n / 2 - 1];
					}
				}
			} else {
				cout << "YES" << endl;
				cout << n / 2 << endl;
				if (n & 1) {
					cout << 3 << " ";
				} else {
					cout << 2 << " ";
				}
				for (int i = 0; i < n / 2 - 1; i++) {
					cout << 2 << " ";
				}
				cout << endl;

			}
		} else {
			cout << "YES" << endl;
			cout << n << endl;
			for (int i = 0; i < n; i++) {
				cout << 1 << " \n"[i == n - 1];
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
