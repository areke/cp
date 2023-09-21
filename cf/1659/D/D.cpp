#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> v(n);
		long long o = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			o += v[i];
		}
		o /= n;
		vector<int> res(n, 0);
		multiset<int> sub;
		for (int i = n - 1; i >= 0; i--) {
			while (!sub.empty() && (*sub.rbegin()) >= i) {
				sub.erase(*sub.rbegin())	;
			}
			if (o && i == 0) {
				res[i] = 1;
			} else if (o && v[i] - (int)sub.size() - 1 > 0) {
				sub.insert(i - o);
				o--;
				res[i] = 1;
			} else {
				sub.insert(i - o);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
