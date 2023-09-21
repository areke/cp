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
		vector<long long> v(n);

		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		int q;
		cin >> q;
		while (q--) {
			long long x, y;
			cin >> x >> y;
			long long d = x * x - 4 * y;
			long long res = 0;
			if (d >= 0) {
				long long sq = sqrt(d);
				if (sq * sq == d && (x + sq) % 2 == 0) {
					long long v1 = (x + sq) / 2;
					long long v2 = (x - sq) / 2;
					set<long long> s = {min(v1, x - v1), min(v2, x - v2)};
					for (auto it : s) {
						long long o = x - it;
						//cout << x << " " << y << " " << it << " " << o << " " << m[it] << " " << m[o] << endl;
						if (o == it) {
							res += m[it] * (m[it] - 1) / 2;
						} else {
							res += m[it] * m[o];
						}
					}
				}
				

			}
			cout << res << " \n"[q == 0];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
