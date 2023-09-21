#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			auto it = s.begin();
			if (*it == p[i]) {
				if (i == n - 1) {
					res[i] = *it;
					swap(res[i], res[i - 1]);
					break;
				}
				it++;
			}
			res[i] = *it;
			s.erase(it);
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
