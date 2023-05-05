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
		vector<string> a(2 * n - 2);
		for (int i = 0; i < 2 * n - 2; i++) {
			cin >> a[i];
		}
		bool b = true;
		for (int i = 0; i < 2 * n - 2; i++) {
			for (int j = 0; j < 2 * n - 2; j++) {
				if (i == j) continue;
				if (a[i].length() == a[j].length() && a[i] != a[j]) {
					string c = a[i];
					string d = a[j];
					reverse(c.begin(), c.end());
					if (c != d) b = false;
				}
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
