#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<array<long long, 3> > v(n);
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v[i] = {i, a, b};
	}
	sort(v.begin(), v.end(), [](auto & a, auto & b) {
		long long y = (a[1] + a[2]) * b[1];
		long long x = (b[1] + b[2]) * a[1];
		if (x == y) {
			return a[0] < b[0];
		}
		return x > y;

	});
	for (int i = 0; i < n; i++) {
		cout << v[i][0] + 1 << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
