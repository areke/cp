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
		for (int i = 0; i < n ;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int s = v[0] + 1;
		int cur = s;
		string res = "YES";
		for (int i = 1; i < v.size(); i++) {
			bool ok = false;
			if (v[i] == cur + 1 || v[i] - 1 == cur + 1 || v[i] + 1 == cur + 1) {
				cur++;
				ok = true;
			} else {
				for (int j = -1; j <= 1; j++) {
					if (v[i] + j >= s && v[i] + j <= cur) ok = true;
				}
			}
			if (!ok) res = "NO";
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
