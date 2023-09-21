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
		long long res = -1e18;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				long long mx = i * j;
				set<int> s;
				for (int k = 1; k <= n; k++) {
					s.insert(k);
				}
				
				bool can = true;
				long long cur = 0;
				long long worst = 0;
				for (int k = n; k >= 1; k--) {
					int allowed = mx / k;
					auto it = s.upper_bound(allowed);
					
					if (it == s.begin()) {
						can = false;
						break;
					}
					it--;
					worst = max(worst, 1LL * k * (*it));
					cur += 1LL * k * (*it);

					s.erase(it);
				}
				//cout << i << " " << j << " " << mx << " " << worst << " " << cur <<  endl;
				if (can) {
					res = max(res, cur - worst);
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
