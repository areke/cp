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
		string res = "";
		vector<int> v;
		bool found = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (v.empty()) {
				v.push_back(x);
				res += '1';
			} else {
				if (!found) {
					if (x >= v[v.size() - 1]) {
						v.push_back(x);
						res += '1';
					} else if (x <= v[0]) {
						v.push_back(x);
						res += '1';
						found = true;
					} else {
						res += '0';
					}
				} else {
					if (x >= v[v.size() - 1] && x <= v[0]) {
						res += '1';
						v.push_back(x);
					} else {
						res += '0';
					}
				}
			}
			
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
