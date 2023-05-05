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
		set<int> x;
		set<int> y;
		for (int i = 0; i < 3; i++) {
			int xx, yy;
			cin >> xx >> yy;
			x.insert(xx);
			y.insert(yy);
		}
		if (x.size() == 3 || y.size() == 3) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
