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
		long long p;
		cin >> p;
		long long orig = p;
		// 1 costs 2
		// 3 costs 3
		// 6 costs 4
		// 10 costs 5 etc
		vector<pair<long long, long long> > v;
		vector<long long> dp(p + 1, 1e9);
		dp[0] = 0;
		long long cur = 1;
		long long s = 0;
		while (s <= p) {
			s += cur;
			if (s > p) break;
			dp[s] = cur + 1;
			v.push_back({s, cur + 1});
			cur++;
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j <= p; j++) {
				if (j + v[i].first > p) break;
				dp[j + v[i].first] = min(dp[j] + v[i].second, dp[j + v[i].first]);
			}
		}
		long long res = dp[p];
		long long res2 = res * (res - 1) / 2;
		res2 -= orig;
		cout << res << " " << res2 << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
