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
	long long MAXI = 100000;
	vector<vector<long long> > fact(MAXI + 1);
	for (int i = 1; i <= MAXI; i++) {
		for (int j = i; j <= MAXI; j += i) {
			fact[j].push_back(i);
		}
	}

	vector<long long> ma(MAXI + 1, 0);
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long low = 0;
		long long high = MAXI;
		long long bad = 2 * MAXI;
		long long res = bad;

		sort(a.begin(), a.end());
		while (low <= high) {
			long long mid = (low + high) / 2;
			int cnt = 0;
			int l = 0;
			bool b = false;
			for (int i = 0; i <= m; i++) {
				ma[i] = 0;
			}
			//set<int>  s;
			for (int i = 0; i < n; i++) {
				for (long long x : fact[a[i]]) {
					if (x > m) continue;
					if (ma[x] == 0) {
						cnt++;
					}
					ma[x]++;
				}
				while (a[l] + mid < a[i]) {
					for (long long x : fact[a[l]]) {
						if (x > m) continue;
						if (ma[x] == 1) {
							cnt--;
						}
						ma[x]--;
					}
					l++;
				}
				if (cnt == m) b = true;
			}
			if (b) {
				high = mid - 1;
				res = min(res, mid);
			} else {
				low = mid + 1;
			}
		}
		if (res == bad) {
			cout << -1 << endl;
		} else {
			cout << res << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
