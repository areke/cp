#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		string s;
		cin >> s;
		string cur = "";
		vector<string> all;
		int ac = 0;
		int bc = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') ac++;
			else bc++;
			if (!cur.empty() && s[i] == cur.back()) {
				all.push_back(cur);
				cur = "";
			}
			cur += s[i];
		}
		if (ac != a + c + d || bc != b + c + d) {
			cout << "NO" << endl;
			continue;
		}
		if (!cur.empty()) {
			all.push_back(cur);
		}
		vector<string> evens;
		for (string & t : all) {
			if (t.size() & 1) {
				if (t[0] == 'A') {
					a--;
				} else {
					b--;
				}
			} else {
				evens.push_back(t);
			}
		}
		sort(evens.begin(), evens.end(), [](const auto & a, const auto & b) {
			return a.length() < b.length();
		});
		for (string & t : evens) {
			if (t[0] == 'A') {
				if (c >= t.size() / 2) {
					c -= t.size() / 2;
				} else {
					a--;
					b--;
				}
			} else {
				if (d >= t.size() / 2) {
					d -= t.size() / 2;
				} else {
					a--;
					b--;
				}
			}
		}
		if (a < 0 || b < 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
 
 
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
 
	return 0;
}