#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		int n, C;
		cin >> n >> C;
		vector<long long> dp(C + 1, 0);
		vector<long long> m(C + 1, 0);
		for (int i = 0; i < n; i++) {
			long long c, d, h;
			cin >> c >> d >> h;
			m[c] = max(m[c], d * h);
		}
		for (int i = 1; i <= C; i++) {
			long long p = m[i];
			for (int j = i; j <= C; j+= i) {
				dp[j] = max(dp[j], p);
				p += m[i];
			}
		}
		
		for (int i = 2; i <= C; i++) {
			dp[i] = max(dp[i - 1], dp[i]);
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			long long D, H;
			cin >> D >> H;
			long long t = D * H;
			auto it = upper_bound(dp.begin(), dp.end(), t);
			if (it == dp.end()) {
				cout << -1 << " \n"[i == q - 1];
			} else {
				cout << it - dp.begin() << " \n"[i == q - 1];
			}
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
