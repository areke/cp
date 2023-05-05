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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		cin >> s;
		int ind = -1;
		for (int i = 1; i < s.length() - 1; i++) {
			if (s[i] == 'a') ind = i;
		}
		string a = "";
		string b = "";
		string c = "";
		if (ind == -1) {
			a = s[0];
			for (int i = 1; i < s.length() - 1; i++) {
				b += s[i];
			}
			c = s[s.length() - 1];
		} else {
			for (int i = 0; i < ind; i++) {
				a += s[i];
			}
			b = s[ind];
			for (int i = ind + 1; i < s.length(); i++) {
				c += s[i];
			}
		}
		cout << a << " " << b << " " << c << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
