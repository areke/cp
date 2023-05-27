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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] % 2 == 0) cnt++;
		}
		int mini = 1e9;
		for (int i = 0; i < n; i++) {
			int x = v[i];
			int cnt = 0;
			while (x % 2 == 0) {
				x /= 2;
				cnt++;
			}
			mini = min(mini, cnt);
		}
		if (cnt == n) {
			cout << mini + cnt - 1 << endl;
		}
		else if (cnt) {
			cout << cnt << endl;
		} else {
			cout << 0 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
