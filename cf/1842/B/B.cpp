#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, x;
		cin >> n >> x;
		vector<vector<long long> > v(3, vector<long long>(n ,0));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		vector<long long> c(3, 0);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				bool b = true;
				for (long long k = 0; k < 32; k++) {
					if (((v[i][j] >> k) & 1) && !((x >> k) & 1)) {
						b = false;
					}
				}
				if (b) c[i] |= v[i][j];
				else break;
			}
		}
		long long res = 0;
		for (int i = 0; i < 3; i++) {
			res |= c[i];
		}
		if (res == x) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
