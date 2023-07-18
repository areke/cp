#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<map<int, int> > c(2);
	long long res = 0;
	for (int i = k / 2 + 1; i < k; i++) {
		c[i % 2][v[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (i >= k / 2 && i + k  - 1 < n) c[i % 2][v[i + k - 1]]++;
		//else cout << i << " " << k << endl;
		res += min({i / 2 + 1, k / 2, (n - i - 1) / 2 + 1});
		res -= c[i % 2][v[i]];
		cout << i << " " << res << endl;
		if (i >= k / 2 + 1) c[i % 2][v[i]]--;
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
