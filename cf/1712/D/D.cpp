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
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long low = 1;
		long long high = 1e9;
		long long res = 0;
		while (low <= high) {
			long long mid = (low + high) / 2;
			int cnt = 0;
			vector<long long> b(a);
			for (int i = 0; i < n; i++) {
				if (2 * b[i] < mid) {
					b[i] = 1e9;
					cnt++;
				}
			}
			int best = 3;
			for (int i = 1; i < n; i++) {
				int cur = 0;
				if (i > 0) {
					if (b[i - 1] < mid) cur++;
				}
				if (b[i] < mid) cur++;
				best = min(best, cur);
			}
			if (cnt + best <= k) {
				res = max(res, mid);
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
