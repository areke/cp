#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

bool good(string & s, string & t) {
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) return false;
	}
	for (int i = 1; i < t.length(); i++) {
		if (t[i] == t[i - 1]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		string s, t;
		cin >> s >> t;
		string c = "";
		string a = s.substr(0, 1);
		string b = t.substr(0, 1);
		for (int i = 1; i < s.length(); i++) {
			c += s[i];
		}
		for (int i = t.length() - 1; i >= 1; i--) {
			c += t[i];
		}
		bool bb = false;

		for (int i = 0; i <= c.length(); i++) {
			string x = a + c.substr(0, i);
			string y = b;
			for (int j = 0; j <= c.length() - i; j++) {
				if (j == 0) continue;
				y += c[c.length() - j];
			}
			//cout << i << " " <<  x << " " << y << endl;
			if (good(x, y)) {
				bb = true;
			}
		}
		if (bb) {
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
