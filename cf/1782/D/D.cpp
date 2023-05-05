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
		int res = 1;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				long long d = a[j] - a[i];
				for (long long k = 1; k <= sqrt(d + 1); k++) {
					if (d % k == 0) {
						long long f1 = min(k, d / k);
						long long f2 = max(k, d / k);
						if ((f1 + f2) % 2 != 0) continue;
						long long y = (f1 + f2) / 2;
						long long z = f2 - (f1 + f2) / 2;
						long long x = y * y - a[j];
						if (x < 0) continue;
						int cnt = 0;
						for (int l = 0; l < n; l++) {
							long long sq = sqrt(a[l] + x);
							if (sq * sq == a[l] + x) {
								cnt++;
							}
						}
						res = max(res, cnt);
					}
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
