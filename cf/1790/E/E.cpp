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
		long long n;
		cin >> n;
		long long cur = n;
		long long maxi = 0;
		for (long long i = 0; i <= 32; i++) {
			if (((long long)1 << i) & n) maxi = i;
		}
		long long a = n, b = 0;
		for (long long i = maxi; i >= 0; i--) {
			if (!(((long long)1 << i) & n)) {
				if (cur >= 2 * (1LL << i)) {
					a += (1LL << i);
					b += (1LL << i);
					cur -= 2LL << i;
				}
			}
		}
		if (cur == 0) {
			cout << a << " " << b << endl;
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
