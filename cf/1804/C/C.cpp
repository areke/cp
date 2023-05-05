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
		long long n, x, p;
		cin >> n >> x >> p;
		long long d = (n - x) % n;
		bool b = false;
		for (long long i = 1; i <= min(2 * n, p); i++) {
			long long dist = (i * (i + 1) / 2) % n;
			if (dist % n == d) b = true;
		}
		if (b) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
