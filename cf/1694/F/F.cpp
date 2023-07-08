#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i< n; i++) {
		cin >> v[i];
	}
	vector<int> d(n);
	int lastInc = -1;
	int lastDec = 1e9 + 10;
	// 4 5 2 6 1 3
	for (int i = 0; i < n - 1; i++) {
		if (v[i] < v[i + 1]) {
			if (i > 0 && v[i] < v[i - 1] && lastInc > v[i]) {
				d[i] = 1;
			} else {
				d[i] = 0;
			}
		}
		else {
			if (i > 0 && v[i] > v[i - 1] && lastDec < v[i]) {
				d[i] = 0;
			} else {
				d[i] = 1;
			}
		}
		if (d[i]) lastDec = v[i];
		else lastInc = v[i];
	}
	d[n - 1] = d[n - 2];
	stack<int> s;
	vector<int> l(n);
	vector<int> g(n);
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) continue;
		while (!s.empty() && v[i] < v[s.top()]) {
			l[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		l[s.top()] = n;
		s.pop();
	}
	int last = n;
	for (int i = n - 1; i >= 0; i--) {
		if (d[i] == 0) last = l[i];
		else l[i] = last;
	}

	for (int i = 0; i < n; i++) {
		if (d[i] == 0) continue;
		while (!s.empty() && v[i] > v[s.top()]) {
			g[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		g[s.top()] = n;
		s.pop();
	}
	last = n;
	for (int i = n - 1; i >= 0; i--) {
		if (d[i] == 1) last = g[i];
		else g[i] = last;
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << l[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << g[i] << " ";
	}
	cout << endl;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += min(g[i], l[i]) - i;
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
