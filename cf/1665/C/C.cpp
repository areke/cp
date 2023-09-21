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
		vector<int> v(n, 0);
		for (int i = 0; i < n - 1; i++) {
			int x;
			cin >> x;
			x--;
			v[x]++;
		}
		v.push_back(1);
		sort(v.begin(), v.end());
		int low = 0;
		int high = n + 1;
		int best = 0;
		assert(v.size() == n + 1);
		while (low <= high) {
			int mid = (low + high) / 2;
			int need = 0;
			int x = 0;
			for (int i = 1; i <= n + 1; i++) {
				if (v[n + 1 - i]) x++;
				else break;
				need += max(0, v[n + 1 - i] - (mid - i) - 1);
			}
			if (need + x > mid) {
				low = mid + 1;
			} else {
				best = mid;
				high = mid - 1;
			}
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
