#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int a, b;
		cin >> a >> b;
		if (a <= b) {
			for (int i = 0; i < a; i++) {
				cout << "10";
			}
			for (int j = 0; j < b - a; j++) {
				cout << "1";
			}
			cout << endl;
		} else {
			for (int i = 0; i < b; i++) {
				cout << "01";
			}
			for (int j = 0; j < a - b; j++) {
				cout << "0";
			}
			cout << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
