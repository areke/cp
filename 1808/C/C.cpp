#include <bits/stdc++.h>
using namespace std;

string can(int mini, int maxi, string & l, string & r) {
	string cur = "";
	int ind = -1;
	assert(l.length() == r.length());
	for (int i = 0; i < l.length(); i++) {
		if (l[i] == r[i]) {
			if (l[i] - '0' < mini || l[i] - '0' > maxi) return "";
			cur += l[i];
		} else {
			ind = i;
			break;
		}
	}
	if (ind == -1){
		assert(cur == l);
		return cur;
	}
	for (char c = l[ind] + 1; c < r[ind]; c++) {
		string nxt = cur;
		if (c - '0' <= maxi && c - '0' >= mini) {
			for (int i = ind; i < l.length(); i++) {
				nxt += c;
			}
			if (nxt >= l && nxt <= r) return nxt;
		}
	}
	string small = cur;
	small += l[ind];

	if (l[ind] - '0' >= mini && l[ind] - '0' <= maxi) {
		for (int i = ind + 1; i < l.length(); i++) {
			small += ('0' + maxi);
		}
		if (small >= l) return small;
	}
	string big = cur;
	big += r[ind];
	if (big[ind] - '0' < mini || big[ind] - '0' > maxi) return "";
	for (int i = ind + 1; i < l.length(); i++) {
		big += ('0' + mini);
	}
	if (big <= r) return big;
	return "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string l, r;
		cin >> l >> r;
		if (l.length() != r.length()) {
			for (int i = 0; i < l.length(); i++) {
				cout << 9;
			}
			cout << endl;
			continue;
		}
		string cur = "";
		int ind = -1;

		int res = 10;
		string ans = l;
		for (int i = 0; i < 10; i++) {
			for (int j = i; j < 10; j++) {
				if (j == 0) continue;
				if (j - i >= res) continue;
				string cur = can(i, j, l, r);
				
				if (cur.length()) {
					//cout << i << " " << j << " "<< cur << endl;
					res = j - i;
					ans = cur;

				}
			}
		}
		cout << ans << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
