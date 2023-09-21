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
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int ind = -1;
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) {
				if (ind != -1) can = false;
				ind = i;
			}
		}
		if (!can || ind == - 1) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			if (v[(i + ind) % n] - v[(i + ind - 1) % n] > 1) can = false;
		}
		if (!can) {
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
