#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n,a,b;
		cin >> n;
		cin >> a;
		cin >> b;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + v[i];
		}
		long long res = p[n] * b;
		for (int i = 0; i < v.size(); i++) {
			long long cur = v[i] * (a + b) + (p[n] - p[i + 1] - (n - i - 1) * v[i]) * b;
			res = min(res, cur);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
