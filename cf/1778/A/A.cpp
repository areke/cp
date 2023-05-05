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
		int n;
		cin >> n;
		vector<long long> a(n);
		long long s = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		long long res = -1e18;
		for (int i = 1; i < n; i++) {
			res = max(res, s + 2 * a[i] * -1 + 2 * a[i - 1] * -1);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
