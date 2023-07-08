#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long b, q, y;
		cin >> b >> q >> y;
		long long c, r, z;
		cin >> c >> r >> z;
		set<long long> f;
		for (int i = 1; i <= sqrt(r) + 1; i++) {
			if (r % i == 0) {
				f.insert(r / i);
				f.insert(i);
			}
		}
		if (r % q != 0) {
			cout << 0 << endl;
			continue;
		}
		if (b > c) {
			cout << 0 << endl;
			continue;
		}
		if ((c - b) % q != 0){
			cout << 0 << endl;
			continue;
		}
		if (b + (y - 1) * q < c + r * (z - 1)) {
			cout << 0 << endl;
			continue;
		}
		long long res = 0;
		for (auto g : f) {
			if (lcm(g, q) != r) continue; 
			long long lb = c - r;
			long long rb = c + r * z;
			if (b > lb) {
				res = -1;
				break;
			}
			if (b + (y - 1) * q < rb) {
				res = -1;
				break;
			}
			res += r / g * r / g;
			res %= MOD;

		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
