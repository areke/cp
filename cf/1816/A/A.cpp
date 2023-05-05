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
		long long x, y;
		cin >> x >> y;
		cout << 2 << endl;
		if (x - 1 < 0) {
			cout << x + 1 << " " << x << endl;
		} else {
			cout << x - 1 << " " << x << endl;
		}
		cout << x << " " << y << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
