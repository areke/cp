#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	vector<vector<int> > v(2);
	vector<vector<int> > e(2);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[x & 1].push_back(x);
		e[x & 1].push_back(i + 1);
	}
	vector<int> ans;
	long long res = 0;
	if (v[0].size() && v[1].size()) {
		res += v[1][0] / 2;
		ans.push_back(e[1][0]);
		for (int x : v[0]) res += x / 2 - 1;
		for (int x : e[0]) ans.push_back(x);
		for (int i = 1; i < v[1].size(); i++) {
			if (i & 1) {
				res += v[1][i] / 2;
			} else {
				res += v[1][i] / 2;
			}
			ans.push_back(e[1][i]);
		}
	} else if (v[0].size()) {
		for (int x : v[0]) res += x / 2;
		for (int x : e[0]) ans.push_back(x);
	} else {
		for (int i = 0; i < v[1].size(); i++) {
			if (i & 1) res += v[1][i] / 2;
			else res += v[1][i] / 2;
			ans.push_back(e[1][i]);
		}
	}
	cout << res << endl;
	assert(ans.size() == n);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
