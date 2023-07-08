#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<long long> x(3), y(3);
		for (int i = 0; i < 3; i++) {
			cin >> x[i] >> y[i];
		}
		long long res = 0;
		long long dx1 = x[1] - x[0];
		long long dx2 = x[2] - x[0];
		long long dy1 = y[1] - y[0];
		long long dy2 = y[2] - y[0];
	//	cout << dx1 << " " << dx2 << " " << dy1 << " " << dy2 << endl;
		if (dy1 >= 0 && dy2 >= 0) {
			res += min(dy1, dy2);
		}
		if (dy1 < 0 && dy2 < 0) {
			res += min(abs(dy1), abs(dy2));
		}
		if (dx1 >= 0 && dx2 >= 0) {
			res += min(dx1, dx2);
		}
		if (dx1 < 0 && dx2 < 0) {
			res += min(abs(dx1), abs(dx2));
		}
		cout << res + 1 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
