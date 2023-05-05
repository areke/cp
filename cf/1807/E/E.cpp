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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + a[i];
		}
		int low = 0;
		int high = n - 1;
		int res = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int k = (mid - low + 1);
			cout << "? " << k << " ";
			for (int j = 0; j < k; j++) {
				cout << low + j + 1;
				if (j == k - 1) cout << endl;
				else cout << " ";
			}
			long long s;
			cin >> s;
			if (s > p[mid + 1] - p[low]) {
				high = mid;
				if (k == 1) {
					res = mid;
					break;
				}
			} else {
				low = mid + 1;
			}
		}
		cout << "! " << res + 1 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
