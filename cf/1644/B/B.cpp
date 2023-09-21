#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			v[i] = n - i;
		}
		for (int i = 0; i < n; i++) {
			if (i > 1 && v[i - 2] + v[i - 1] == v[i]) {
				swap(v[i - 2], v[i]);
				for (int j = 0; j < n; j++) {
					cout << v[j] << " \n"[j == n - 1];
				}
				swap(v[i - 2], v[i]);
				swap(v[i], v[i + 1]);
				continue;

			}
			for (int j = 0; j < n; j++) {
				cout << v[j] << " \n"[j == n - 1];
			}
			if (i != n - 1) {
				swap(v[i], v[i + 1]);
			}
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
