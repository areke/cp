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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int res = 0;
		for (int i = 1; i < n - 1; i++) {
			if (v[i] > v[i - 1] + v[i + 1]) res++;
		}
		if (k > 1) {
			cout << res << endl;
		} else {
			res = n / 2;
			if (n % 2 == 0) res--;
			cout << res << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
