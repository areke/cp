#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		vector<long long> v(n);
		v[0] = 0;
		set<long long> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		long long missing = 0;
		for (int i = 1; i < n; i++) {
			cin >> v[i];
			
		}
		bool can = true;
		for (int i = 0; i < n; i++) {
			if (v[i] > 1e11) {
				can = false;
			}
		}
		if (!can) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			if (s.count(v[i] - v[i - 1])) {
				s.erase(v[i] - v[i - 1]);
			} else {
				missing = v[i] - v[i - 1];
			}
		}
		if (v[n - 1] != (n * (n + 1)) / 2) {
			missing =  (n * (n + 1)) / 2 - v[n - 1];
		}

		//cout << missing << endl;
		for (auto it : s) {
			//cout << it << endl;
			missing -= it;
		}
		if (missing == 0) {
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
