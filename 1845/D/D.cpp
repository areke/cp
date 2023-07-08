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
		vector<long long> s(n + 1, 0);
		vector<long long> m(n + 1, 0);
		for (int i = n - 1; i >= 0; i--) {
			s[i] = v[i] + s[i + 1];
			m[i] = max(m[i + 1], s[i]);
		}
		
		long long cur = 0;
		long long best = 0;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (cur + m[i] > best) {
				best = cur + m[i];
				res = cur;
			}
			cur += v[i];
		}
		if (cur > best) {
			res = cur;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
