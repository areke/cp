#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		int maxi = 1;
		for (int i = 2; i <= 100; i++) {
			if (n % i != 0) {
				maxi = i - 1;
				break;
			}
		}
		cout << maxi << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
