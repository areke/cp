#include <bits/stdc++.h>
using namespace std;


int dfs(int x, vector<vector<int> > & v, int last = -1) {
	int zc = 0;
	int res = 0;
	for (int n : v[x]) {
		if (n == last) continue;
		int val = dfs(n, v, x);
		if (val == 0) zc++;
		else res += val;
	}
	return res + max(0, zc - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<vector<int> > v(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (v[i].size() > 2) {
				ind = i;
			}
		}
		if (ind == -1) {
			cout << 1 << endl;
			continue;
		}
		vector<int> d(n, 0);
		cout << dfs(ind, v) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
