#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		int x, y;
		cin >> x >> y;
		string res = "YES";
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			if ((a + b) % 2 == (x + y) % 2) {
				res = "NO";
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
