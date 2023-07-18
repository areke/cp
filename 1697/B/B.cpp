#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		int n, q;
		cin >> n >> q;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = v[i] + p[i];
		}
		for (int i = 0; i < q; i++) {
			long long x, y;
			cin >> x >> y;
			cout << p[x] - p[x - y]  << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
