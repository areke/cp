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
		vector<long double> m;
		vector<long double> d;
		for (int i = 0; i < 2 * n; i++) {
			long long x, y;
			cin >> x >> y;
			if (x == 0) {
				m.push_back(abs(y));
			} else {
				d.push_back(abs(x));
			}
		}
		sort(m.begin(), m.end());
		sort(d.begin(), d.end());
		long double res = 0;
		for (int i = 0; i < n; i++) {
			res += sqrt(m[i] * m[i] + d[i] * d[i]);
		}
		cout << fixed << setprecision(12) << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
