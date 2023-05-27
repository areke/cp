#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> m(1e6 + 1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x]++;
	}
	int res = 1;
	for (int i = 1; i <= 1e6; i++) {
		int cnt = 0;
		for (int j = i; j <= 1e6; j += i) {
			cnt += m[j];
		}
		if (cnt >= 2) res = i;
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
