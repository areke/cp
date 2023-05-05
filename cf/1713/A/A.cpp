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
		int minx = 0;
		int miny = 0;
		int maxx = 0;
		int maxy = 0;
		for (int i= 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			maxx = max(maxx, x);
			minx = min(minx, x);
			maxy = max(maxy, y);
			miny = min(miny, y);
		}
		cout << 2 * ((maxx - minx) + (maxy - miny)) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
