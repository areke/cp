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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> s(n, 0);

		vector<long long> a(n, 0);
		long long sub = 0;
		long long res = 0;
		for (int i = 1; i < n; i++) {
			if (v[i] > v[i - 1]) {
				s[i] = v[i] - v[i - 1];
				res += v[i] - v[i - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			sub += s[i];
			a[i] = v[i] - sub;
		}
		long long mini = 1e9;
		for (int i = 0; i < n; i++) {
			mini = min(mini, a[i]);
		}
		if (mini < 0) {
			for (int i = 0; i < n; i++) {
				a[i] = a[i] - mini;
			}
			res -= mini;
		}
		res += a[0];
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
