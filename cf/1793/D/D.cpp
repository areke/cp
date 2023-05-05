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
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> p(n);
		vector<int> q(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}
		map<int, int> a;
		map<int, int> b;
		for (int i = 0; i < n; i++) {
			a[p[i]] = i;
			b[q[i]] = i;
		}
		// mex of full array
		long long res = 1;
		long long mini = min(a[1], b[1]);
		long long maxi = max(a[1], b[1]);
		res += mini * (mini + 1) / 2;
		res += (maxi - mini - 1) * (maxi - mini) / 2;
		res += (n - maxi - 1) * (n - maxi) / 2;
		//if (n > 3) cout << res << endl;
		long long l = mini;
		long long r = maxi;

		for (int i = 2; i <= n; i++) {
			long long x = min(a[i], b[i]);
			long long y = max(a[i], b[i]);
			
			long long b1 = -1;
			long long b2 = n;
			if (x < l) {
				b1 = max(b1, x);
			} else {
				b2 = min(b2, x);
			}
			if (y < l) {
				b1 = max(b1, y);
			} else {
				b2 = min(b2, y);
			}
			long long c1 = l - b1;
			long long c2 = b2 - r;
			
			if ((x < l || x > r) && (y < l || y > r)) {
				//if (n > 3) cout << l << " " << r << " " << b1 << " " << b2 << " " << x << " " << y << endl;
				//cout << c1 << " " << c2 << endl;
				res += c1 * c2;
			}
			l = min(l, min(x, y));
			r = max(r, max(x, y));
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
