#include <bits/stdc++.h>
using namespace std;


long long solve(set<long long> & a) {
	long long x1 = *a.begin();
	long long x2 = *a.rbegin();
	return (x2 - x1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		set<long long> left, right, up, down;
		int w, h;
		cin >> w >> h;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			down.insert(x);
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			up.insert(x);
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			left.insert(x);
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			right.insert(x);
		}
		long long res = 0;
		res = max(res, solve(down) * h);
		res = max(res, solve(up) * h);
		res = max(res, solve(left) * w);
		res = max(res, solve(right) * w);
		
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
