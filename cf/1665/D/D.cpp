#include <bits/stdc++.h>
using namespace std;

long long query(long long a, long long b) {
	cout << "? " << a << " " << b << endl;
	long long x;
	cin >> x;
	return x;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long cur = 0;
		for (int i = 0; i < 30; i++) {
			
			long long a = (1 << i) - cur;
			long long b = (1 << (i + 1)) + (1 << i) - cur;

			long long next = query(a, b);
			if (next != (1LL << (i))) {
				cur += (1 << i);
			}
		}
		cout << "! " << cur << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
