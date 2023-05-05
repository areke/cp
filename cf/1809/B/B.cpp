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
		long long low = 0;
		long long high = 1e9 + 2;
		long long best = 1e9 + 2;
		while (low <= high) {
			long long mid = (low + high) / 2;
			long long x = mid;
			long long c = 2*x*(x+1)+1;
			if (x % 2 == 0) {
				c = (x + 1) * (x + 1);
			}  else {
				c -= (x) * (x);
			}
			if (c >= n) {
				best = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
