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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// consider "peaks"
		// if more than one peak has max length, ans = 0
		// if peak has different length on each side, ans = 0
		// if peak has same length on each side, and length is even, ans = 1
		// else ans = 0
		vector<int> l(n, 0);
		vector<int> r(n, 0);
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				cnt++;
			} else {
				cnt = 0;
			}
			l[i] = cnt;
		}
		cnt = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				cnt++;
			} else {
				cnt = 0;
			}
			r[i] = cnt;
		}
		vector<int> v(n, 0);
		int m = 0;
		for (int i = 0; i < n; i++) {
			v[i] = max(l[i], r[i]);
			m = max(v[i], m);
		}
		cnt = 0;
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (m == v[i]) {
				cnt++;
				ind = i;
			}
		}
		if (cnt > 1) {
			cout << 0 << endl;
		}else if (l[ind] != r[ind]) {
			cout << 0 << endl;
		} else if (l[ind] % 2 == 1) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}


	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
