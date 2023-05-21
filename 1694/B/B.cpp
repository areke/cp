#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n;
		string s;
		cin >> n >> s;
		long long res = n;
		for (int i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				res += i - 1 + 1;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
