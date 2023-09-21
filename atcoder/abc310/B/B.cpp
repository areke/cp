#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<set<int> > v(n);
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			int c;
			cin >> c;
			for (int j = 0; j < c; j++) {
				int x;
				cin >> x;
				v[i].insert(x);
			}
		}
		bool res = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				bool ok = true;
				if (p[i] >= p[j]) {
					for (int x : v[i]) {
						if (!v[j].count(x)) ok = false;
					}
					if (p[i] == p[j] && v[j].size() <= v[i].size()) {
						ok = false;
					}
				} else {
					ok = false;
				}
				res = res || ok;
			}
		}
		if (res) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
