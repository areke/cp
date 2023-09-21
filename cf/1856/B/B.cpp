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
		map<long long, int> m;
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			s += v[i];
			m[v[i]]++;
		}
		if (n == 1) {
			cout << "NO" << endl;
			continue;
		}
		int best = 0;
		for (auto it : m) {
			if (it.second > m[best]) {
				best = it.first;
			}
		}
		if (best != 1) {
			cout << "YES" << endl;
		} else {
			if (m[best] + n <= s) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
