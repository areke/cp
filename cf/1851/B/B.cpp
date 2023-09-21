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
		vector<vector<int> > v(2);
		vector<int> a(n);
		for (int i = 0; i< n; i++) {
			cin >> a[i];
			v[a[i] % 2].push_back(a[i]);
		}
		for (int i = 0; i < 2; i++) {
			sort(v[i].begin(), v[i].end());
		}
		int c[2] = {0};
		vector<int> res;
		for (int i = 0; i < n; i++) {
			res.push_back(v[a[i] % 2][c[a[i] % 2]]);
			c[a[i] % 2]++;
		}
		string can = "YES";
		for (int i = 1; i < n; i++) {
			if (res[i] < res[i - 1]) {
				can = "NO";
			}
		}
		cout << can << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
