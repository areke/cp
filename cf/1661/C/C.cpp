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
		vector<long long> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		sort(h.begin(), h.end());
		long long ans = 1e18;
		for (int j = 0; j < 3; j++) {
			long long t = h[n - 1] + j;
			long long res = 1e18;
			long long low = 0;
			long long high = 1e18;
			while (low <= high) {
				long long mid = (low + high) / 2;
				long long one = mid / 2 + mid % 2;
				long long two = mid / 2;
				bool can = true;
				for (int i = 0; i < n; i++) {
					if ((t - h[i]) % 2) {
						one--;
					}
				}
				if (one < 0) can = false;
				for (int i = 0; i < n; i++) {
					long long d = (t - h[i]) / 2 * 2;
					if (two > 0) {
						long long take = min(two, d / 2);

						//cout << "1 "  << mid << " " << d << " " << two << " " << one <<" " << take << endl;
						two -= take;
						d -= take * 2;
					}
					if (one > 0) {
						long long take = min(one, d);
						one -= take;
						d -= take;
					}
					if (d > 0) can = false;
				}
				if (can) {
					high = mid - 1;
					res = min(res, mid);
				} else {
					low = mid + 1;
				}
			}
			ans = min(res, ans);
		}
		cout << ans << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
