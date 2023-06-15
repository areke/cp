#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	set<int> a;
	set<int> b;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '(' && s[i + 1] == '(') {
			a.insert(i);
		}
		if (s[i] == ')' && s[i + 1] == ')') {
			b.insert(i);
		}
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		x--;
		if (x > 0) {
			if (s[x - 1] == ')' && s[x] == ')') {
				b.erase(x - 1);
			}
			if (s[x - 1] == '(' && s[x] == '(') {
				a.erase(x - 1);
			}
		}
		if (x < n - 1) {
			if (s[x + 1] == ')' && s[x] == ')') {
				b.erase(x);
			}
			if (s[x + 1] == '(' && s[x] == '(') {
				a.erase(x);
			}
		}
		if (s[x] == '(') s[x] = ')';
		else s[x] = '(';
		if (x > 0) {
			if (s[x - 1] == ')' && s[x] == ')') {
				b.insert(x - 1);
			}
			if (s[x - 1] == '(' && s[x] == '(') {
				a.insert(x - 1);
			}
		}
		if (x < n - 1) {
			if (s[x + 1] == ')' && s[x] == ')') {
				b.insert(x);
			}
			if (s[x + 1] == '(' && s[x] == '(') {
				a.insert(x);
			}
		}

		if (n % 2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		if (s[0] == ')' || s[n - 1] == '(') {
			cout << "NO" << endl;
			continue;
		}
		if (a.empty() && b.empty()) {
			cout << "YES" << endl;
		} else if (a.empty() || b.empty()) {
			cout << "NO" << endl;
		} else {
			if (((*a.begin()) < (*b.begin())) && ((*a.rbegin()) < (*b.rbegin()))) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}

	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
