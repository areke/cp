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
		vector<int> a(n);
		

		vector<int> b(n, 0);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i] = {a[i], i};
		}

		bool ok = true;
		sort(v.begin(), v.end());
		if (v[0].first == n) {
			for (int i = 0; i < n; i++) {
				b[i] = i + 1;
			}
		} else if (v[n - 1].first == 0) {
			for (int i = 0; i < n; i++) {
				b[i] = (-i - 1);
			}
		} else {
			int curn = n;
			int g = 0;
			int ind = n - 1;
			for (int i = 0; i < n; i++) {
				if (!b[v[i].second]) {

					if (v[i].first - g == curn) {
						b[v[i].second] = curn--;
						//cout << i << " " << curn << " " << v[i].first << " " << b[v[i].second] << endl;

						continue;
					} else {
					
						b[v[i].second] = -(curn - (v[i].first - g));
						//cout << i << " " << curn << " " << v[i].first << " " << b[v[i].second] << endl;

					}
					


					int nextn = abs(b[v[i].second]) - 1;
					for (int j = curn; j > abs(b[v[i].second]); j--) {
						//cout << "? " << j << endl;
						//assert(!b[v[j - 1].second]);
						b[v[ind--].second] = j;
						g++;
					}
					curn = nextn;
				}
			}
			for (int i = 0; i < n; i++) {
				if (b[i] > n || b[i] < -n || b[i] == 0) {
					ok = false;
				}
			}
			set<int> all;
			for (int i = 0; i < n; i++) {
				all.insert(b[i]);
			}
			if (all.size() != n) ok = false;
			vector<int> av;
			for (int x : all) av.push_back(x);
			for (int i = 0; i < n; i++) {
				auto it = lower_bound(av.begin(), av.end(), -b[i]) - av.begin();
				int cnt = n - it;
				if (a[i] != cnt) ok = false;
			}
			
		}
		if (ok) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << b[i] << " \n"[i == n - 1];
			}
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
