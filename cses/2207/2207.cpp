#include <bits/stdc++.h>
using namespace std;

string res = "0 1 2 4 7 10 20 23 26 50 53 270 273 276 282 285 288 316 334 337 340 346 359 362 365 386 389 392 566 630 633 636 639 673 676 682 685 923 926 929 932 1222";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	stringstream ss(res);
	for (int i = 0; i < 42; i++) {
		int x;
		ss >> x;
		s.insert(x);
	}
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++) {
		int x;
		cin >> x;
		if (s.find(x) != s.end()) {
			cout << "second" << endl;
		} else {
			cout << "first" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
