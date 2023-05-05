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
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		int orig = s.length();
		if (s[0] == '_') s = "^" + s;
		if (s[s.length() - 1] == '_') s += "^";
		if (s.length() < 2) s += "^";
		int res = 0;
		int cnt = 0;
		for (int i =0; i < s.length(); i++) {
			if (s[i] == '_') cnt++;
			else {
				res += max(0, cnt - 1);
				cnt = 0;
			}
		}
		res += (s.length() - orig);
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
