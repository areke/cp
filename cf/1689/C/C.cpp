#include <bits/stdc++.h>
using namespace std;


int solve(int x, vector<vector<int> > & v, int last = -1) {
	int res = 1e9;
	vector<int> c;
	for (int n : v[x]) {
		if (n == last) continue;
		c.push_back(n);
	}
	if (c.size() == 0) return 1;
	if (c.size() == 1) return 2;
	return min(2 + solve(c[0], v, x), 2 + solve(c[1], v, x));
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
		cout << n - solve(0, v) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
