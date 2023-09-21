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
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		if (n & 1) {
			cout << "NO" << endl;
			continue;
		}
		sort(v.begin(), v.end());
		vector<int> res;
		for (int i = 0; i < n / 2; i++) {
			res.push_back(v[i]);
			res.push_back(v[i + n / 2]);
		}
		swap(res, v);
		bool can = true;
		for (int i = 0; i < n; i++) {
			int l = v[(i + n - 1) % n];
			int r = v[(i + n + 1) % n];
			if (!((v[i] > l && v[i] > r) || (v[i] < l && v[i] < r))) {
				can = false;
			}
		}
		swap(res, v);
		if (!can) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << res[i] << " \n"[i == n - 1];
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
