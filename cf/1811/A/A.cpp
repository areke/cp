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
		int n,  d;
		cin >> n >> d;
		string s;
		cin >> s;
		string res = s;
		res += ('0' + d);
		for (int i = 0; i < s.length(); i++) {
			if (d > (s[i] - '0')) {
				res = s.substr(0, i);
				res += ('0' + d);
				res += s.substr(i, s.length() - i);
				break;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
