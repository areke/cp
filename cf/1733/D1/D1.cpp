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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

long long cost(long long a, long long b, long long x, long long y) {
	if (b < a) swap(a, b);
	if (b - a == 1) return x;
	return min((b - a) * x, y);
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		long long n, x, y;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;
		vector<int> inds;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) inds.push_back(i);
		}
		if (inds.size() % 2 == 1) {
			cout << -1 << endl;
			continue;
		}
		if (inds.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<long long> dp(inds.size() + 1, 1e18);
		dp[0] = 0;
		dp[1] = min(x, y);
		dp[2] = min(cost(inds[0], inds[1], x, y), 2*y);
		for (int i = 3; i < dp.size(); i++) {
			dp[i] = min(dp[i - 2]  +cost(inds[i - 2], inds[i - 1], x, y), dp[i]);
			if (i % 2 == 0) {
				dp[i] = min(dp[i], dp[i - 1]);
			} else {
				dp[i] = min(dp[i], dp[i - 1] + y);
			}
		}
		for (int i = 0; i <= dp.size(); i++) {
			//cout << dp[i] << " ";
		}
		cout << dp[inds.size()] << endl;
	}

	return 0;
}
