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
		int n, q;
		cin >> n >> q;
		vector<long long> a(n);

		long long s= 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + a[i];
		}
		for (int i =0; i < q; i++) {
			long long l, r, k;
			cin >> l >> r >> k;
			long long cur = s + (r - l + 1) * k - (p[r] - p[l - 1]);
			if (cur % 2) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
