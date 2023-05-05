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
long long n;

void fix(long long & a) {
	if (a > n / 2) {
		a -= n / 2;
	} else {
		a = n / 2 - a + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		fix(x1);
		fix(x2);
		fix(y1);
		fix(y2);
		cout << abs(max(x1, y1) - max(x2, y2)) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
