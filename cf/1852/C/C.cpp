#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n + 2, 0);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			a[i] %= k;
		}
		long long res = 0;
		multiset<long long> s;
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] > a[i - 1]) {
				long long cur = a[i] - a[i - 1];
				res += cur;
				if (!s.empty()) {
					s.insert(cur);
					auto it = s.begin();
					res += *it - cur;
					s.erase(it);
				}
				
			} else if (a[i] < a[i - 1]) {
				long long cur = a[i] + k - a[i - 1];
				s.insert(cur);
			}
		}
		cout << res << endl;

	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
