#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<long long> v(3);
		for (int i = 0; i < 3; i++) cin >> v[i];
		sort(v.begin(), v.end());
		bool can = false;
		if (v[0] + v[1] == v[2]) {
			can = true;
		}
		if (v[0] % 2 == 0 && v[1] == v[2]) {
			can = true;
		}
		if (v[1] % 2 == 0 && v[0] == v[2]) {
			can = true;
		}
		if (v[2] % 2 == 0 && v[0] == v[1]) {
			can = true;
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
