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
		string act = "";
		for (int i = 1; i <= 60; i++) {
			if (i % 3 == 0) {
				act += 'F';
			}	
			if (i % 5 == 0) {
				act += 'B';
			}
		}
		bool b = false;
		for (int i = 0; i < 31; i++) {
			if (s == act.substr(i, n)) {
				b = true;
			}
		}
		if (b) {
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
