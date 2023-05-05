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
		long long n, m;
		cin >> n >> m;
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		long long res = min(n, m);
		a= min(a, n + 1 - a);
		b = min(b, m + 1 - b);
		c = min(c, n + 1 - c);
		d = min(d, m + 1 - d);
		res = min(res, min(a + b, c + d));
		res = min(res, 2 * a + 1);
		res = min(res, 2 * b + 1);
		res = min(res, 2 * c + 1);
		res = min(res, 2 * d + 1);
		cout << min(4LL, res) << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
