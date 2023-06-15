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
		vector<vector<int> > v;
		vector<int> c(n + 1, 0);
		for (int i = 0; i < n; i++ ){
			int l, r;
			cin >> l >> r;
			v.push_back({l, r});
			for (int j = l; j <= r; j++) {
				c[j]++;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int mini = v[i][0];
			for (int j = v[i][0]; j <= v[i][1]; j++) {
				if (c[j] < c[mini]) {
					mini = j;
				}
			}
			cout << v[i][0] << " " << v[i][1] << " " << mini << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
