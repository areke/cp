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
		map<int, int> m;
		for (int i = 0; i < 2 * n; i++) {
			int x;
			cin >> x;
			m[x]++;
		}
		string res = "YES";
		for (auto it : m) {
			if (it.second > n) res = "NO";
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
