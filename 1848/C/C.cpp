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
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int res = -1;
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0 && b[i] == 0) continue;
			long long cnt = 0;
			long long x = a[i];
			long long y = b[i];
			while (x != 0 && y != 0) {
				if (x >= 2 * y) {
					long long num = x / (2 * y);
					x = x % (2 * y);
					cnt += num * 3;
				} else {
					long long c = abs(x - y);
					x = y;
					y = c;
					cnt++;
				}
			}
			if (x != 0) {
				assert(y == 0);
				cnt++;
			}

			if (x == 0 && y == 0) continue;
			cnt %= 3;
			if (res == -1) {
				res = cnt % 3;
			} else {
				if (res != cnt) {
					can = false;
					break;
				}
			}
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
