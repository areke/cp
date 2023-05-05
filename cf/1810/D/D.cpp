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
		int q;
		cin >> q;
		long long l = 1;
		long long r = 1e18;
		vector<long long> res;
		for (int i = 0; i < q; i++) {
			//cout << i << " " << l << " " << r << endl;
			int t;
			cin >> t;
			if (t == 1) {
				long long a, b, n;
				cin >> a >> b >> n;
				long long nl, nr;
				if (n == 1) {
					nl = max(l, 1LL);
				} else {
					nl = max(l, (a - b) * (n - 2) + a + 1);
				}
				nr = min(r, (a - b) * (n - 1) + a);
				if (nl > nr) {
					res.push_back(0);
				} else {
					res.push_back(1);
					l = nl;
					r = nr;
				}
			} else {
				long long a, b;
				cin >> a >> b;
				long long lr = 1;
				long long rr = 1;
				if (a < l) {
					lr = (l - a) / (a - b) + 1;
					if ((l - a) % (a - b) != 0) lr++;
				}
				if (a < r) {
					rr = max(1LL, (r - a) / (a - b) + 1);
					if ((r - a) % (a - b) != 0) rr++;
				}
				if (lr == rr) {
					res.push_back(lr);
				} else {
					res.push_back(-1);
				}
			}
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i == res.size() - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
