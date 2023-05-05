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
		string s;
		cin >> n;
		cin >> s;
		char first = s[0];
		int su = 0;
		if (s[0] == '1') su++;
		string res = "";
		for (int i = 1; i < n; i++) {
			if (s[i] == '1') {
				if (su == 1) {
					res += '-';
					su = 0;
				} else {
					res += '+';
					su = 1;
				}
			} else {
				res += '+';
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
