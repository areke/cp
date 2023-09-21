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
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		} 
		int res = 0;
		for (int i = 1; i < n; i++) {
			if (v[i] < v[i - 1]) {
				res++;
				i++;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
