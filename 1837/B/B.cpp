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
		int cnt = 1;
		char c = s[0];
		int res = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				cnt++;
			} else {
				cnt = 1;
 
			}
			res = max(res, cnt);
		}
		int x = 0;
		cout << res + 1 << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}