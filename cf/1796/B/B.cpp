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


bool check(string & a, string & c) {
	int ind = 0;
	for (int i = 0; i < a.length(); i++) {
		while (ind < c.length() && c[ind] != a[i] && c[ind] != '*') {
			ind++;
		} 
		if (ind >= c.length()) return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		string a, b;
		cin >> a >> b;
		string res = "";
		if (a[0] == b[0]) {
			cout << "YES" << endl;
			res += a[0];
			res += '*';
			cout << res << endl;
			continue;
		} else if (a[a.length() - 1] == b[b.length() - 1]) {
			cout << "YES" << endl;
			res += '*';
			res += a[a.length() - 1];
			cout << res << endl;
			continue;
		} 
		for (char c = 'a'; c <= 'z'; c++) {
			if (res.length()) break;
			for (char d = 'a'; d <= 'z'; d++) {
				string t1 = "";
				t1 += c;
				t1 += d;
				if (a.find(t1) != string::npos && b.find(t1) != string::npos) {
					res = "*";
					res += c;
					res += d;
					res += '*';
					break;
				}
			}
		}
		if (res.length() > 0) {
			cout << "YES" << endl;
			cout << res << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
