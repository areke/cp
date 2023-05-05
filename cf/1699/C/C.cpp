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
		vector<int> a(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = i;
		}
		int l = 1e9;
		int r = -1;
		// [3, 3]
		// [0, 0]
		// [0, 3]
		// [0, 3]
		// [5, 5]
		// [0, 5]
		long long res = 1;
		long long MOD = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			//cout << i << " " << .l << " " << r << " " << m[a[i]] << endl;
			if (m[i] >= l && m[i] <= r) {
				res *= (r - l + 1 - i);
				res %= MOD;
			}
			l = min(l, m[i]);
			r = max(r, m[i]);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
