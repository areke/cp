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
		vector<long long> res(n + 1, 0);
		vector<long long> c(n + 1, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x <= n) {
				c[x]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j+= i) {
				res[j] += c[i];
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, res[i]);
		}
		cout << ans << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
