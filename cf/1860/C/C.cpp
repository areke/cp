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
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		stack<int> s;
		vector<int> l(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() && v[s.top()] > v[i]) {
				l[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
		int mini = 1e9;
		int res = n;
		for (int i = 0; i < n; i++) {
			
			if (v[i] >= mini || l[i] == -1) {
				res--;
			}
			if (l[i] != -1) {
				mini = min(mini, v[i]);
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
