#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, h;
		cin >> n >> m >> h;
		vector<vector<long long> > v(n);
		for (int i = 0; i < n; i++) {
			vector<int> x(m);
			for (int j = 0; j < m; j++) {
				cin >> x[j];
			}
			sort(x.begin(), x.end());
			long long s = 0;
			int p = 0;
			long long pen = 0;
			for (int j = 0; j < m; j++) {
				if (x[j] + s > h) break;
				s += x[j];
				pen += s;
				p++;
			}
			v[i] = {p, -pen, -i};
		}
		sort(v.begin(), v.end());
		int res = 1;
		for (int i = 0; i < n; i++) {
			if (v[n - i - 1][2] == 0) {
				break;
			}
			res++;
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
