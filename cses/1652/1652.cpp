#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(n, 0));
	vector<vector<int> > p(n, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') v[i][j] = 1;
			else v[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j + 1] = p[i][j] + v[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		c--;
		d--;
		long long res = 0;
		for (int j = a; j <= c; j++) {
			res += p[j][d + 1] - p[j][b];
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
