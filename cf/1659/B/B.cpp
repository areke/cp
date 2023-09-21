#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		string t = "";
		for (int i = 0; i < n; i++) {
			if (k & 1) {
				t += ((s[i] - '0') ^ 1) + '0';
			} else {
				t += s[i];
			}
		}
		vector<int> res(n, 0);
		for (int i= 0; i < n; i++) {
			if (t[i] == '0' && k) {
				res[i]++;
				k--;
				t[i] = '1';
			}
		}
		if (k) {
			res[n - 1] += k;
		}
		if (k & 1) {
			t[n - 1]  = ((t[n - 1] - '0') ^ 1) + '0';
		}
		cout <<t << endl;
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
