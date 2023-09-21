#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		long long d1 = 2e9;
		long long d2 = 2e9;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				d1 = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '1') {
				d2 = (n - i - 1);
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') cnt++;
		}
		//cout << d1 << " " << d2 << endl;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += 11 * (s[i] - '0');
		}
		if (d2 + d1 <= k && cnt > 1) {
			res -= 11;
		} else if (d2 <= k) {
			res -= 10;
		} else if (d1 <= k) {
			res -= 1;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
