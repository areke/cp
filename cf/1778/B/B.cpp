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
		int n, m, d;
		cin >> n >> m >> d;
		vector<int> p(n);
		vector<int> a(m);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		vector<int> ip(n + 1, 0);
		for (int i =0; i < n; i++) {
			ip[p[i]] = i;
		}
		long long res = 1e18;
		for (int i = 1; i < m; i++) {
			int x = ip[a[i - 1]];
			int y = ip[a[i]];
			if (x >= y || y > (x + d)) {
				res = 0;
			} else {
				res = min(res,(long long) y- x);
				if (d < n - 1) {
					res = min(res, (long long) x + d - y + 1);
				}
			}
			//cout << i << " " << x << " " << y << " " << x + d << endl;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
