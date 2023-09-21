#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v(8);
	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}
	string res = "Yes";
	for (int i = 0; i < 8; i++) {
		if (v[i] < 100 || v[i] > 675 || v[i] % 25 != 0) res = "No";
		if (i && v[i] < v[i - 1]) res = "No";
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
