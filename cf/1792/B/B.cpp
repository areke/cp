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
		if (a == 0) {
			cout << 1 << endl;
			continue;
		}
		long long res = a + 2 * min(b, c) + min(a, d);
		long long left = a - min(a, d);
		res += min(left, max(b, c) - min(b, c));
		if (res < a + b + c + d) {
			res++;
		}
		
		cout << res << endl;

		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
