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
		int n = s.length();
		vector<int> l(n + 1, 0);
		vector<int> r(n + 1, 0);
		for (int i = 0; i < n; i++) {
			l[i + 1] = (s[i] == '1') + l[i];
		}
		for (int i = n -1; i >= 0; i--) {
			r[i] = (s[i] == '0') + r[i + 1];
		}
		long long res = 1e18;
		long long cost = 1000000000001;
		for (int i = 0; i < n; i++) {
			res = min(res, l[i] * cost + r[i + 1] * cost);
			if (i > 0 && s[i] == '0' && s[i - 1] == '1') {
				res = min(res, l[i] * cost + r[i + 1] * cost - 1);
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
