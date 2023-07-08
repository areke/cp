#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, m;
		cin >> n >> m;
		map<int, long long> mp;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			mp[x]++;
		}
		long long reg = n - mp.size();
		assert(n >= 0);
		long long low = 0;
		long long high = 1e6;
		long long res = -1;
		while (low <= high) {
			long long mid = (low + high) / 2;
			long long f = (mid / 2) * reg;
			for (auto it : mp) {
				long long done = min(mid, it.second);
				f += done;
				f += (mid - done) / 2;
			}
			if (f >= m) {
				res = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
