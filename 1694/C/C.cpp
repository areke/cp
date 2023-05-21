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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long can = 0;
		bool res = true;
		bool found = false;
		for (int i = n - 1; i >= 1; i--) {
			if (v[i] != 0) found = true;
			can -= v[i];
			if (found && can <= 0) res = false;
		}
		can -= v[0];
		if (can != 0) res = false;
		if (res) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
