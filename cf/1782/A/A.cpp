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
		long long w, d, h;
		cin >> w >> d >> h;
		long long res = 1e18;
		long long a, b, f, g;
		cin >> a >> b >> f >> g;
		res = min(res, h + a + abs(g-b) + f);
		res = min(res, h + (w - a) + abs(g - b) + w - f);
		res = min(res, h + b + abs(f - a) + g);
		res = min(res, h + (d - b) + abs(f - a) + d - g);
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
