#include <bits/stdc++.h>
using namespace std;

bool check(string & t) {
	int c = 0;
	for (int i = 0; i < t.length(); i++) {
		if (t[i] == '(') c++;
		else c--;
		if (c < 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> p(s.length() + 1, 0);
		int mini = 0;
		for (int i = 0; i < s.length(); i++) {
			p[i + 1] = p[i] + (s[i] == '(' ? 1 : -1);
			mini = min(mini, p[i + 1]);
		}
		if (mini == 0) {
			cout << 0 << endl;
			continue;
		}
		int l = -1, r = -1;
		for (int i = 0; i < s.length(); i++) {
			if (l == -1 && p[i + 1] < 0) l = i;
			if (p[i + 1] < 0) r = i;
		}
		int li = -1;
		int ri = 2 * n - 1;
		for (int i = 0; i < l; i++) {
			if (p[i + 1] > p[li + 1]) li = i;
		}
		for (int i = r + 1; i < 2 * n; i++) {
			if (p[i + 1] > p[ri + 1]) ri = i;
		}
		string t = s;
		reverse(t.begin() + li + 1, t.begin() + ri + 1);
		bool ok = check(t);
		if (ok) {
			cout << 1 << endl;
			cout << li + 2 << " " << ri + 1 << endl;
			continue;
		}
		t = s;		
		int ind = 0;
		for (int i = 0; i < s.length(); i++) {
			if (p[i + 1] > p[ind + 1]) ind = i;
		}
		cout << 2 << endl;
		cout << 1 << " " << ind + 1 << endl;
		cout << ind + 2 << " " << 2 * n << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
