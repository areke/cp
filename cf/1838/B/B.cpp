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
		vector<int> v(n);
		vector<int> p(n + 1, 0);

		for (int i = 0; i< n; i++) {
			cin >> v[i];
			p[v[i]] = i + 1;
		}
		if (p[1] > p[2]) swap(p[1], p[2]);
		if ((p[1] <= p[n] && p[n] <= p[2])) {
			cout << p[1] << " " << p[2] << endl;
		} else if (p[n] <= p[1]) {
			cout << p[1] << " " << p[n] << endl;
		} else {
			cout << p[n] << " " << p[2] << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
