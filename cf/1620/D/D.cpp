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
		set<long long> all;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			all.insert(a[i]);
		}
		set<int> s;
		sort(a.begin(), a.end());
		bool same = true;
		for (int i = 0; i < n; i++) {
			s.insert(a[i] % 3);
			if (a[i] % 3 != a[0] % 3) same = false;
		}
		if (same) {
			long long res = a[n - 1] / 3 + (a[n - 1] % 3 != 0);
			cout << res << endl;
			continue;
		}
		if (a[n - 1] % 3 == 0) {
			cout << a[n - 1] / 3 + 1 << endl;
			continue;
		} else {
			long long res = a[n - 1] / 3 + 1;
			if (!s.count(1) || !s.count(2)) {
				cout << res << endl;
			} else {
				if (a[0] == 1 || a[n - 1] % 3 == 2 || all.count(a[n - 1] / 3 * 3)) {
					cout << res + 1 << endl;
				} else {
					cout << res << endl;
				}
			}
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
