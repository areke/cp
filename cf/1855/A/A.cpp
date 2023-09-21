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
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x == i) cnt++;
		}
		int res = cnt / 2;
		if (cnt & 1) res++;
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
