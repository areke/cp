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
#include <numeric>
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
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cin >> b[i];
		}
		vector<long long> d(n, 1);
		d[0] = 1;
		long long cur = 1;
		long long g = a[0];
		for (int i = 1; i < n; i++) {
			bool can = false;
			long long l = lcm(b[i - 1] * d[i - 1], b[i]);
			long long x1 = l / b[i - 1] / d[i - 1];
			long long x2 = l / b[i];
			if (g % x1 == 0 && a[i] % x2 == 0) {
				g /= x1;
				d[i] = x2;
				can = true;
				g = gcd(g, a[i] / x2);
			}
			if (!can) {
				g = a[i];
				cur++;

			}
		}
		cout << cur << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
