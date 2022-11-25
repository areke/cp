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
#include <cstring>
using namespace std;


long long x, y;

long long dist(long long i, long long j) {
	if (abs(i - j) == 1) return min(x, 2 * y);
	return min(abs(i - j) * x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;
		vector<int> inds;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				inds.push_back(i);
			}
		}
		if (inds.size() % 2) {
			cout << -1 << endl;
			continue;
		}
		if (x >= y) {
			if (inds.size() == 0) {
				cout << 0 << endl;
				continue;
			} else if (inds.size() > 2) {
				cout << y * inds.size() / 2 << endl;
			} else {
				if (inds[0] + 1 == inds[1]) {
					if (a.length() == 2) {
						cout << x << endl;
					} else {
						cout << min(x, 2 * y) << endl;
					}
				} else {
					cout << y << endl;
				}
			}
			continue;
		}
		vector<long long> dp(inds.size() + 1, 1e18);
		dp[0] = 0;
		for (int i = 0; i < inds.size(); i++) {
			if ((i + 1) % 2) {
				dp[i + 1] = min(dp[i], dp[i + 1]);
				if (i > 0) {
					dp[i + 1] = min(dp[i + 1], dp[i - 1] + dist(inds[i], inds[i - 1]));
				}
			} else {
				if (i > 0) {
					dp[i + 1] = min(dp[i + 1], dp[i - 1] + dist(inds[i], inds[i - 1]));
				}
				dp[i + 1] = min(dp[i + 1], dp[i] + y);
			}
		}
		cout << dp[dp.size() - 1] << endl;
	}
	return 0;
}
