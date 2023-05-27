#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	vector<long long> p(k);
	for (int i = 0; i < k; i++) {
		cin >> p[i];
	}
	long long res = 0;
	for (int i = 1; i < (1 << k); i++) {
		long long cur = n;
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			if ((1 << j) & i) {
				cnt++;
				cur /= p[j];
			}
		}
		if (cnt % 2) res += cur;
		else res -= cur;
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
