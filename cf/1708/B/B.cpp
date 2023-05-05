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
		long long n, l, r;
		cin >> n >> l >> r;
		bool b = true;
		vector<long long> res(n);
		for (long long i = n; i >= 1; i--) {
			long long x = l / i;
			if (l % i != 0) {
				x++;
			}
			long long cur = x * i;
			// 23 22 21 20 25 24
				// 18 20 
			if (cur > r) {
				b = false;
				break;
			} else {
				res[i - 1] = cur;
			}
		}
		if (b) {
			cout << "YES" << endl;

			for (int i = 0; i < n; i++) {
				cout << res[i] << " ";
			}
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
