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
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool L = false;
		bool R = false;
		int res = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == 'L' && s[i + 1] == 'R') res = i + 1;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') L = true;
			if (s[i] == 'R') R = true;
		}
		if (!L || !R) {
			cout << -1 << endl;
		} else {
			cout << res << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
