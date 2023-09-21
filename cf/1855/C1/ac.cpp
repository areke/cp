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
		vector<int> v(n);
		int maxi = 0;
		int mini = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			maxi = max(maxi, v[i]);
			mini = min(mini, v[i]);
		}
		if (maxi == 0 && mini == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<pair<int, int> > res;
		int gz = 0;
		int lz = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > 0) gz++;
			if (v[i] < 0) lz++;
		}
		if (abs(maxi) >= abs(mini)) {
			if (lz + 19 > 31) {
				int ind = -1;
				for (int i = 0; i < n; i++) {
					if (v[i] < 0) {
						ind = i;
					}
				}
				assert(ind != -1);
				for (int i = 0; i < 5; i++) {
					res.push_back({ind, ind});
					v[ind] *= 2;
				}
			}
		} else {
			if (gz + 19 > 31) {
				int ind = -1;
				for (int i = 0; i < n; i++) {
					if (v[i] > 0) {
						ind = i;
					}
				}
				assert(ind != -1);
				for (int i = 0; i < 5; i++) {
					res.push_back({ind, ind});
					v[ind] *= 2;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, v[i]);
			mini = min(mini, v[i]);
		}
		if (abs(maxi) >= abs(mini)) {
			int ind = -1;
			for (int i = 0; i < n; i++) {
				if (v[i] == maxi) ind = i;
			}
			for (int i = 0; i < n; i++) {
				if (v[i] < 0) {
					res.push_back({i, ind});
				}
			}
			for (int i = 0; i < n - 1; i++) {
				res.push_back({i + 1, i});
			}
		} else {
			int ind = -1;
			for (int i = 0; i < n; i++) {
				if (v[i] == mini) ind = i;
			}
			for (int i = 0; i < n; i++) {
				if (v[i] > 0) {
					res.push_back({i, ind});
				}
			}
			for (int i = n - 1; i > 0; i--) {
				res.push_back({i - 1, i});
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
		}
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}