#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		long long q;
		cin >> n >> k >> q;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> cnt;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] <= q) {
				cur++;
			} else {
				if (cur) cnt.push_back(cur);
				cur = 0;
			}
		}
		if (cur) {
			cnt.push_back(cur);
		}
		long long res = 0;
		for (long long x : cnt) {
			if (x >= k) {
				res += (x - k + 1) * (x - k + 2) / 2;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
