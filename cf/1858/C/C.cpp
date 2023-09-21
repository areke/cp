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
		set<int> vis;
		vector<int> res;
		for (int i = 1; i <= n; i++) {
			if (vis.count(i)) continue;
			for (int j = i; j <= n; j *= 2) {
				res.push_back(j);
				vis.insert(j);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[ i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
