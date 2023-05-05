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
		vector<long long> c(n);
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		sort(c.begin(), c.end());
		long long cur = 1;
		if (c[0] != 1) {
			cout << "NO" << endl;
			continue;
		}
		bool res = true;
		for (int i = 1; i < n; i++) {
			if (c[i] <= cur) {
				cur += c[i];
			} else {
				res = false;
			}
		}
		if (res) {
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
