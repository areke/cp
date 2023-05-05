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
		int cur = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cur ^= x;
		}
		if (n % 2 == 0) {
			if (cur == 0) {
				cout << 0 << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			cout << cur << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
