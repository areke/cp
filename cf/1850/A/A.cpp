#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<int> a(3);
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}
		string res = "NO";
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (a[i] + a[j] >= 10) res = "YES";
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
