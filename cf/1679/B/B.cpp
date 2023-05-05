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
		long long n, q;
		cin >> n >> q;
		long long s = 0;

		map<int, int> m;
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			m[i] = x;
			s += x;
		}
		long long v = 0;
		for (int i = 0; i < q; i++) {
			int t;
			cin >> t;
			if (t == 1) {
				long long ind, x;
				cin >> ind >> x;
				ind--;
				long long old = v;
				if (m.count(ind)) {
					old = m[ind];
				}
				//cout << i << " " << ind << " " << old << " " << x << endl;
				m[ind] = x;
				s += x - old;
			} else {
				long long x;
				cin >> x;
				s = n * x;
				v = x;
				m.clear();
			}
			cout << s << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
