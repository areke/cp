#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	map<int, int> m;
	m[x] = 0;
	int res = -1;
	for (int i = 1; i <= 1000; i++) {
		cout << "+ " << 1 << endl;
		int y;
		cin >> y;
		if (m.count(y)) {
			res = i;
			break;
		}
		m[y] = i;
	}
	if (res != -1) {
		cout << "! " << res << endl;
		return 0;
	}
	for (int i = 1; i <= 1000; i++) {
		cout << "+ " << 1000 << endl;
		int y;
		cin >> y;
		if (m.count(y)) {
			res = 1000 * (i + 1) - m[y];
			break;
		}
	}
	assert(res != -1);
	cout << "! " << res << endl;



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
