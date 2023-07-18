#include <bits/stdc++.h>
using namespace std;

int get(vector<int> & a) {
	for (int i = 1; i <= a.size(); i *= 2) {
		bool can = true;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != a[(j + i) % a.size()]) {
				can = false;
				break;
			}
		}
		if (can) return i;
	} 
	return 1;
}

bool ok(vector<int> & a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = 0;
	while (!ok(a)) {
		int p = get(a);
		int k = max(p / 2, 1);
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			b[i] = a[i] ^ a[(i + k) % n];
		}
		a = b;
		res += k;
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
