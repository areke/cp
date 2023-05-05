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
		map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		int res = 4;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] == 4) {
				res = -1;
			} else if (m[s[i]] == 3) {
				res = 6;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
