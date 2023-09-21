#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		long long n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<map<int, vector<int> > > m(2);
		for (int i = 0; i < n; i++) {
			m[i & 1][v[i]].push_back(i);
		}

		long long res = (n - k + 1) * (k / 2);
		for (int i = 0; i < n; i++) {
			int rs = n - i - (k / 2 + 1);

			int l = max(i + 2LL, i + k - 1 - 2 * i);
			int r = min(i + rs * 2LL, i + k - 1);

			//cout << i << " " << l << " " << r << " " << rs << endl;
			if (r < l) continue;
			
			auto it = lower_bound(m[i & 1][v[i]].begin(), m[i & 1][v[i]].end(), l) - m[i & 1][v[i]].begin();
			auto it2 = lower_bound(m[i & 1][v[i]].begin(), m[i & 1][v[i]].end(), r + 1) - m[i & 1][v[i]].begin();
			//cout << l << " " << r << " " << it << " " << it2 << endl;
			res -= it2 - it;
		}
		cout << res << endl;


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
