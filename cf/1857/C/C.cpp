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
		map<int, int> m;
		for (int i = 0; i < n * (n - 1) / 2; i++) {
			int x;
			cin >> x;
			m[x]++;
		}
		int cur = n - 1;
		vector<int> a(n, 1e9);
		int ind = 0;
		for (auto it : m) {
			while (it.second > 0) {
				it.second -= cur;
				cur--;
				a[ind++] = it.first;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
