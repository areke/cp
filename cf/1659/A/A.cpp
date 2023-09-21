#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, r, b;
		cin >> n >> r >> b;
		string res = "";
		int cnt = r / (b + 1);
		int mod = r % (b + 1);
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < cnt; j++) {
				res += 'R';
			}
			if (mod > 0) {
				res += 'R';
				mod--;
			}
			res += 'B';
		}
		for (int i = 0; i < cnt; i++) {
			res += 'R';
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
