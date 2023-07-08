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
		string s;
		cin >> s;
		if (s[0] == '9') {
			string res = "";
			for (int i = 0; i <n; i++) {
				res += '0';
			}
			int carry = 0;
			for (int i = n - 1; i >= 0; i--) {
				if ('1' >= carry + s[i]) {
					res[i] = '0' + ('1' - carry - s[i]);

					carry = 0;
				} else {
					res[i] = '0' + (('1' + 10) - carry - s[i]);
					carry = 1;
				}
				
			}
			cout << res << endl;
		} else {
			string res = "";
			for (int i = 0; i < n; i++) {
				res += ('9' - s[i]) + '0';
			}
			cout << res << endl;

		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
