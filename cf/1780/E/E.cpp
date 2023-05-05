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

// if g is in the set, all factors of g are in the set
// from 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long l, r;
		cin >> l >> r;
		long long res = max((long long) 0, r / 2 - l + 1);
		long long a = l;
		for (long long g = 1; g <= sqrt(l) && g < l; g++) {
			long long ll = l / g + 1;
			if (l % g != 0) ll++;
			ll *= g;
			if (ll <= r) res++;
		}
		long long g = sqrt(l) + 1;
		while (g < l) {
			long long f = l / g;
			if (l % g != 0) f++;
			
			long long low = g;
			long long high = l - 1;

			long long b = g;
			while (low <= high) {
				long long mid = (low + high) / 2;
				long long cur = l / mid;
				if (l % mid != 0) cur++;
				if (cur != f) {
					high = mid - 1;
				} else {
					b = mid;
					low = mid + 1;
				}
			}
			
			long long n = min(b, r / (f + 1));
			//if  (l == 1) cout << n << " " << f << " " << g << " " << b << " " << max((long long)0, n - g + 1) << endl;
			if (n >= g) {
				res += n - g + 1;
			}
			g = b + 1;
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
