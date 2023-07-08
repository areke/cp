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
		vector<long long> v;
		set<long long> s;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			s.insert(x);
		}
		long long low = 0;
		long long high = 1e18;
		long long best = 1e18;
		
		while (low <= high) {
			long long mid = (low + high) / 2;
			bool can = false;
			long long cur = 0;
			for (int i = 0; i < 3; i++) {
				auto it = s.lower_bound(cur);
				if (it == s.end()) {
					can = true;
					break;
				}
				cur = *it + 2 * mid + 1;
			}
			if (cur > *s.rbegin()) can = true;
			if (can) {
				high = mid - 1;
				best = mid;
			} else {
				low = mid + 1;
			}

		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
