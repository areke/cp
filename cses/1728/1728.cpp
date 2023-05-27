#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	double res = 0;
	for (int i = 0; i < n; i++) {
		double cur =0 ;
		for (int j = i + 1; j < n; j++) {
			for (int k = 1; k <= r[j]; k++) {
				cur += ((double)max(0, r[i] - k)) / ((double) r[j]);
			}
		}
		cur /= (double)(r[i]);
		res += cur;
	}

	cout << fixed << setprecision(6) << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
