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
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		long long x = a;
		long long y = b;
		if (d < b) {
			cout << -1 << endl;
			continue;
		}
		long long res = 0;
		res += (d - b);
		x += (d- b);
		y += (d - b);
		if (x < c) {
			cout << -1 << endl;
			continue;
		}
		res += (x - c);
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
