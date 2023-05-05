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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		if (k == 0) {
			cout << "YES" << endl;
		} else {
			bool b = true;
			for (int i = 0; i < k; i++) {
				if (s[i] != s[s.length() - i - 1]) b = false;
			}
			if (2 * k + 1 > s.length()) b = false;
			if (n % 2 == 0 && 2 * k + 2 > s.length()) b = false;
			if (b) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
