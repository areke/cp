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

// 1 2 3 4

// 1 2 | 1
// 1 2 3 | 2
// 1 2 3 4 | 
// 1 2 3 4 5


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		vector<long long> a(n);

		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long res = n / 2;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				res = max(res, i * (n - i));
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
