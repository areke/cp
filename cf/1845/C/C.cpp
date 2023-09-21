#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<vector<int> > v(10);
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			v[s[i] - '0'].push_back(i);
		}
		int m;
		cin >> m;
		string l, r;
		cin >> l >> r;
		int cur = 0;
		bool res = false;
		for (int i = 0; i < m; i++) {
			int last = cur;
			for (char j = l[i]; j <= r[i]; j++) {
				auto it = lower_bound(v[j - '0'].begin(), v[j - '0'].end(), cur);
				if (it == v[j - '0'].end()) {
					res = true;
					break;
				}
				last = max(last, *it + 1);
			}
			cur = last;
			if (res) break;
		}
		if (res) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
