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
		long long a, b;
		cin >> a >> b;
		long long res = 1e18;
		long long besta = 1e18;
		long long bestb = 1e18;
		for (long long i = 1; i <= max(100LL, (long long) (2 * max(sqrt(a) + 1, sqrt(b) + 1))); i++) {
			long long cura = a / i + (a % i != 0);
			long long curb = b / i + (b % i != 0);
			
			besta = min(besta, cura);
			bestb = min(bestb, curb);
			res = min(res, besta + bestb + i - 1);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
