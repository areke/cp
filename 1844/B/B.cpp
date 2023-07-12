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
		if (n == 1) {
			cout << 1 << endl;
			continue;
		} else if (n == 2) {
			cout << 1 << " " << 2 << endl;
			continue;
		}
		vector<int> p(n, 0);
		p[0] = 2;
		p[n / 2] = 1;
		p[n - 1] = 3;
		int cnt = 4;
		for (int i = 0; i < n; i++) {
			if (!p[i]) {
				p[i] = cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << p[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
