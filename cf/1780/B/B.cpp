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
#include <numeric>
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
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		long long c = 0;
		long long res = 0;
		for (int i = 0; i < n - 1; i++) {
			c += a[i];
			res = max(res, gcd(c, s - c));
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
