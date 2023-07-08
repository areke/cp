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
		int k;
		cin >> k;
		vector<int> v(n, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int cur = (i + 1) / (k);
			if ((i + 1) % k) cur++;
			if (cnt < cur) {
				v[i] = 1;
				cnt++;
			}
		}
		cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			cnt += v[i];
			int cur = (n - i) / k;
			if ((n - i) % k) cur++;
			if (cnt < cur) {
				v[i] = 1;
				cnt++;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += v[i];
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
