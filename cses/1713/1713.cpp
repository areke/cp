#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	vector<int> v(1e6 + 1, 0);
	for (int i = 1; i <= 1e6; i++) {
		for (int k = i; k <= 1e6; k+=i) {
			v[k]++;
		}
	}
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int x;
		cin >> x;
		cout << v[x] << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
