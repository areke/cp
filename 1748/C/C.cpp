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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<long long, int> m;
		long long cur = 0;
		long long best = 0;

		vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
		int last = -1;
		for (int i = 0; i < n; i++) {

			cur += a[i];
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][1];
			if (a[i] == 0) {
				dp[i + 1][0] = dp[i][0] + 1;
				dp[i + 1][1] = dp[i][0];
				last = i;
				m.clear();
				cur = 0;
			} else {
				m[cur]++;
				if (cur == 0) {
					dp[i + 1][0] = max(dp[i + 1][0], dp[last + 1][0] + m[cur]);
				} else if (last != -1) {
					dp[i + 1][0] = max(dp[i + 1][0], dp[last + 1][1] + m[cur]);
				}
			}
		}
		long long res = 0;
		for (int i = 0; i <= n; i++) {
			//cout << dp[i][0] << " " << dp[i][1] << endl;
			res = max(dp[i][0], res);
		}
		cout << res << endl;
	}
	return 0;
}
