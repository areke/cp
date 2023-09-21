#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		char last = s[0];
		int cnt = 1;
		int res = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == '0' && s[i - 1] == '0') res+= 2;
			if (i > 1 && s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '0') {
				res++;
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
