#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector<int> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + (s[i] - '0');
		}
		vector<int> o(n, 0);
		vector<int> z(n, 0);
		o[n - 1] = n;
		if (o[n - 1] == '1') o[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '1') o[i] = i;
			else o[i] = o[i + 1];
		}
		z[0] = -1;
		if (z[0] == '0') z[0] = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0') z[i] = i;
			else z[i] = z[i - 1];
		}
		set<pair<int, int> > res;
		for (int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			int x = o[l];
			int y = z[r];
			if (x >= y) {
				res.insert({-1, -1});
			} else {
				res.insert({x, y});
			}
			//cout << x << " " << y << endl;

		}
		cout << res.size() << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}