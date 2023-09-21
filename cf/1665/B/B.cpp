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
		map<int, int> m;
		for (int i = 0; i < n ;i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		int maxi = 0;
		for (auto it : m) {
			maxi = max(maxi, it.second);
		}
		long long res = n - maxi;
		while (maxi < n) {
			res++;
			maxi *= 2;
		}

		cout << res << endl; 
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
