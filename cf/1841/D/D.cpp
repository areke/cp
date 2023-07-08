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
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].second >> v[i].first;
		}
		sort(v.begin(), v.end());
		map<int, vector<int > > m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				//cout << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << endl;
				if (v[j].first >= v[i].second) {
					m[i].push_back(j);
				}
			}
		}
		vector<int> used(n, 0);
		int last = -1e9;
		for (int i = 0; i < n; i++) {
			if (!m[i].empty() && !used[i] && v[i].second > last) {
				for (int j : m[i]) {
					if (!used[j] && v[j].second > last) {
						used[j] = 1;
						used[i] = 1;
						last = v[i].first;
						break;
					}
				}
			}
		}
		int u = 0;
		for (int i = 0; i < n; i++) {
			u += used[i];
		}
		cout << n - u << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
