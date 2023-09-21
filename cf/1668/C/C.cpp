#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long res = 1e18;
	for (int i = 0; i < n; i++) {
		long long cur = 0;
		long long num = 0;
		for (int j = i - 1; j >= 0; j--) {
			long long nxt = num / v[j];
			num = (nxt + 1) * v[j];
			cur += nxt + 1;
		}
		num = 0;
		for (int j = i + 1; j < n; j++) {
			long long nxt = num / v[j];
			num = (nxt + 1) * v[j];
			cur += nxt + 1;
		}
		res = min(res, cur);
	}
	cout << res << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
