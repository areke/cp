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
		vector<long long> a(n);
		vector<pair<long long, int> > c(2, {1e18, 0});
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[i & 1] = min(c[i & 1], {a[i], i});
		}
		if (n & 1) {
			cout << "Mike" << endl;
		} else {
			if (c[0] > c[1]) {
				cout << "Mike" << endl;
			} else {
				cout << "Joe" << endl;
			}
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
