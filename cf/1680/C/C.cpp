#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		int n = s.length();
		int low = 0;
		int high = n;
		vector<int> o(n + 1, 0);
		vector<int> z(n + 1, 0);
		for (int i = 0; i < n; i++) {
			o[i + 1] = o[i] + (s[i] - '0');
			z[i + 1] = z[i] + (1 - (s[i] - '0'));
		}
		int res = n;

		while (low <= high) {
			int mid = (low + high) / 2;
			bool pos = false;
			for (int i = 0, j = 0; i <= n; i++) {
				if (o[i] > mid) break;
				while (j + 1 <= n && (o[n] - o[j]) + o[i] > mid) {
					j++;
				}
				if (z[j] - z[i] <= mid) pos = true;
			}
			if (pos) {
				high = mid - 1;
				res = mid;
			} else {
				low = mid + 1;
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
