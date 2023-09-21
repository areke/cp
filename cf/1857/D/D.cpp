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
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<pair<int, int> > c(n);
		for (int i = 0; i < n; i++) {
			c[i] = {a[i] - b[i], i};
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		vector<int> res = {c[0].second};
		for (int i = 1; i < n; i++) {
			if (c[i].first != c[i - 1].first) break;
			res.push_back(c[i].second);
		}
		cout << res.size() << endl;
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << " \n"[i == res.size() - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
