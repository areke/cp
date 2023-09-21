#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		int n = s.length();
		string res = "";
		int carry = 0;
		vector<int> v(n + 1, 0);
		for (int i = 0; i < n; i++) {
			v[n - i] = s[n - i - 1] - '0';
		}
		int z = n + 1;
		for (int i = n; i>= 0; i--) {
			v[i] += carry;
			carry = 0;
			if (v[i] > 9) {
				v[i] %= 10;
				carry = 1;
			}
			if (v[i] >= 5) {
				z = i;
				carry = 1;
			}
		}
		if (v[0] != 0) {
			res += '0' + v[0];
		}
		for (int i = 1; i <= n; i++) {
			if (i >= z) res += '0';
			else res += '0' + v[i];
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
