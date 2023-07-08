#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> p(n, 0);
		int cnt = 0;
		vector<int> u(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (u[i]) continue;
			for (int k = i; k <= n; k *= 2) {
				p[cnt++] = k;
				u[k] = 1;
			}
		}
		cout << 2 << endl;
		for (int i = 0; i < n; i++) {
			cout << p[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
