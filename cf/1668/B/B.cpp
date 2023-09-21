#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<long long> v(n);
		for (int i = 0; i < n ;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long res = 0;
		for (int i = 1; i < n; i++) {
			res += v[i];
		}
		res += v[n - 1];
		res += n;
		if (res <= m) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
