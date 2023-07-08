#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> v(n);
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s += v[i];
		}
		long long maxi = 0;
		long long cur = 0;
		vector<long long> res(n, -1);
		for (int i = 1; i <= n; i++) {
			cur += v[i - 1];
			long long t = cur / i;
			if (cur % i != 0) t++;
			maxi = max(maxi, t);
			long long rest = s;
			long long rt = rest / i;
			if (rest % i != 0) rt++;
			res[i - 1] = max(maxi, rt);
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			long long x;
			cin >> x;
			auto it = upper_bound(res.rbegin(), res.rend(), x);
			if (it == res.rbegin()) {
				cout << -1 << endl;
			} else {
				cout << res.rend() - it + 1 << endl;
			}

		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
