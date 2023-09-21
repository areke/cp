#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long x, y, n;
    cin >> x >> y >> n;
    long long s = (n - 1) * n / 2;
    if (x + s > y) {
      cout << -1 << endl;
      continue;
    }
    long long diff = y - s - x;
    long long l = x;
    cout << l << " ";
    for (int i = n - 1; i > 0; i--) {
      l = l + i;
      cout << l + diff << " \n"[i == 1];
    }
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
