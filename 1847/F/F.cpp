#include <bits/stdc++.h>
using namespace std;


const int MAXN = 2e5;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, q;
		cin >> n >> q;
		
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<array<long long, 2> > v;
		v.push_back({0, a[0]});
		vector<int> c(31, -1);
		for (int i = 0; i < 31; i++) {
			if ((a[0] >> i) & 1) c[i] = 0;
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j < 31; j++) {
				if (c[j] == -1 && (a[i] >> j) & 1) {
					c[j] = i;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			vector<pair<int, int> > vv;
			for (int j = 0; j < 31; j++) {
				if ((a[i] >> j) & 1) c[j] = i;
			}
			for (int j = 0; j < 31; j++) {
				if (c[j] != -1) {
					int cur = 0;
					if (c[j] <= i) {
						cur = i - c[j];
					} else {
						cur = i + (n - c[j]);
					}
					vv.push_back({cur, a[c[j]]});
				}
			}
			sort(vv.begin(), vv.end());
			int val = 0;
			for (int j = 0; j < vv.size(); j++) {
				if (j + 1 < vv.size() && vv[j].first == vv[j + 1].first) continue;
				val |= vv[j].second;
				v.push_back({1LL * vv[j].first * (n - 1) + i, val});
			}
			
		}
		long long best = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			swap(v[i][0], v[i][1]);
			if (v[i][0] > best) best = v[i][0];
			v[i][0] = best;
		}
		for (int i = 0; i < q; i++) {
			int val;
			cin >> val;
			array<long long, 2> s = {val, (long long) 1e18};
			auto it = upper_bound(v.begin(), v.end(), s);
			if (it == v.end()) {
				cout << -1 << "\n";
			} else {
				cout << (*it)[1] + 1 << "\n";
			}
		}

		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
