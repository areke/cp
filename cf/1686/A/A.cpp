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
		set<int> s;
		int x = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s.insert(v[i]);
			x += v[i];
		}
		if (x % n != 0 || !s.count(x / n)) {
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
