#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long x, d;
		cin >> x >> d;
		long long d2 = d;
		int p = 0;
		long long prime = d;
		for (int i = 2; i * i <= d; i++) {
			if (d % i == 0) {
				p++;
				prime = i;
				if (d / i != i) p++;
			}
		}
		long long sq = d * d;
		long long c = sq * d;
		if (x % sq != 0) {
			cout << "NO" << endl;
		} else {
			if (p < 2) {
				long long y = x/ sq;
				
				int cnt = 2;
				while (y % d == 0) {
					y /= d;
					cnt++;
				}
				long long need = 0;
				long long y2 = y;
				while (y2 % prime == 0) {
					y2 /= prime;
					need++;
				}
				int cur = 0;
				long long z = prime;
				while (z != d) {
					z *= prime;
					cur++;
				}

				bool can = false;
				if ((cnt - 1) * cur >= cur + 1 + need) {
					can = true;
				}
				//cout << can << " " << cur << " " << cnt << endl;

				int pc = 0;
				if (y % (prime * prime) == 0) can = true;
				else if (y % prime == 0) {
					pc = 1;
				}
				while (y % prime == 0) {
					y /= prime;
				}
				for (int i = 2; i * i <= y; i++) {
					if (y % i == 0) can = true;
				}
				if (y != 1) pc++;
				if (pc >= 2) can = true;
				if (can) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}

			} else {
				
				long long div = 0;
				bool can = false;
				long long y = x / sq;
				for (int i = 2; i * i <= y; i++) {

					if (y % i == 0) {
						can = true;
					}
				}
				if (can) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
