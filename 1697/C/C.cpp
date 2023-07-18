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
		string a, b;
		cin >> a >> b;
		string x = "";
		string y = "";
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != 'b') x += a[i];
		}
		for (int i = 0; i < n; i++) {
			if (b[i] != 'b') y += b[i];
		}
		if (x != y) {
			cout << "NO" << endl;
			continue;
		}
		auto check = [n](string & s, char c) {
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (s[i] == c) v.push_back(i);
			}
			return v;
		};
		vector<int> s = check(a, 'a');
		vector<int> t = check(b, 'a');
		bool can = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] > t[i]) can = false;
		}
		s = check(a, 'c');
		t = check(b, 'c');
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < t[i]) can = false;
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
