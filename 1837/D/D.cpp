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
		int mini = 0;
		int maxi = 0;
		int cnt = 0;
		vector<int> res(n, 0);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') cnt++;
			else cnt--;
			mini = min(mini, cnt);
			maxi = max(maxi, cnt);
			if (cnt < 0) res[i] = 2;
			else if (cnt > 0) res[i] = 1;
			else if (cnt == 0) {
				res[i] = res[i - 1];
			}
		}
		if (cnt != 0) {
			cout << -1 << "\n";
			continue;
		}
		if (mini >= 0 || maxi <= 0) {
			cout << 1 << "\n";
			for (int i = 0; i < n; i++) {
				cout << 1 << " \n"[i == n - 1];
			}
			continue;
		}

		cout << 2 << "\n";
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n -1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
