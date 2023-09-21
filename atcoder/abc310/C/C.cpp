#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<string> all;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		string t = "";
		for (int j = x.length() - 1; j >= 0; j--) {
			t += x[j];
		}
		if (x < t) {
			all.insert(x);
			//cout << x << endl;
		} else {
			all.insert(t);
			//cout << t << endl;
		}
	}
	cout << all.size() << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
