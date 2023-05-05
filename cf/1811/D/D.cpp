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

vector<long long> fib(46, 0);

bool can(long long n, long long x, long long y, bool col) {
	// f[n] rows, f[n + 1] cols 
	if (n == 1) {
		if (col) return (x == 1 && (y == 1 || y == 2));
		else return (y == 1 && (x == 1 || x == 2));
	}
	if (col) {
		if (y > fib[n]) {
			return can(n - 1, x, y - fib[n], col ^ true);
		} else {
			// y <= fib[n]
			// need fib[n + 1] - fib[n] > y
			if (fib[n + 1] - y < fib[n]) return false;
			return can(n - 1, x, y, col ^ true);
		}
	} else {
		if (x > fib[n]) {
			return can(n - 1, x - fib[n], y,  col ^ true);
		} else {
			if (fib[n + 1] - x < fib[n]) return false;
			return can(n - 1, x, y, col ^ true);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < 46; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, x, y;
		cin >> n >> x >> y;
		if (can(n, x, y, true)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
