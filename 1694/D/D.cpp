#include <bits/stdc++.h>
using namespace std;

long long solve (int x, int & res, vector<int> & l, vector<int> & r, vector<vector<int> > & v, int last) {
	long long s = 0;
	for (int n : v[x]) {
		if (n == last) continue;
		s += solve(n, res, l, r, v, x);
	}
	if (l[x] > s || v[x].empty()) {
		res++;
		return r[x];
	} else {
		return min(s, (long long)r[x]);
	}
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
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			x--;
			v[i].push_back(x);
			v[x].push_back(i);
		}
		vector<int> l(n);
		vector<int> r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		vector<int> dp;
		int res = 0;
		solve(0, res,  l, r, v, -1);
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
