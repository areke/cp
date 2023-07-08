#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		set<char> ss;
		for (char c : s){
			ss.insert(c);
		}
		map<char, int> m;
		for (int i = 0; i < ss.size(); i++) {
			m[s[i]] = i;
		}
		bool can = true;
		for (int i = 0; i < s.length(); i++) {
			if (m[s[i]] != i % ss.size()) {
				can = false;
			}
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
	return 0;
}
