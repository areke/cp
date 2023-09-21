#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int cur = 0;
		int l = n + 1;
		for (int i = 0; i < n; i++) {
			if (v[i] == v[0]) {
				cur++;
			}
			if (cur == k) {
				l = i;
				break;
			}
		}
		cur = 0;
		int r = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] == v[n - 1]) {
				cur++;
			}
			if (cur == k) {
				r = i;
				break;
			}
		}
		if (l <= r || (v[0] == v[n - 1] && l < n)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
