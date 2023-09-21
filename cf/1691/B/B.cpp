#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		map<int, vector<int> > m;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x].push_back(i);
		}
		bool can = true;
		for (auto it : m) {
			if (it.second.size() == 1) can = false;
		}
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		vector<int> res(n, 0);
		for (auto it : m) {
			for (int i = 0; i < it.second.size(); i++) {
				res[it.second[i]] = it.second[(i + 1) % it.second.size()];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] + 1 << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
