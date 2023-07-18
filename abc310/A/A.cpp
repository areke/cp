#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, q;
	cin >> n >> p >> q;
	int res = p;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res = min(res, q + x);
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
