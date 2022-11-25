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


// ending state must be all 1s
//
// if ant is going to index i, all portals from [0, i - 1] must be 1
// let f(x) = next portal index after position x (binsearch)

// dp[i] = how long it takes to get to portal i with [0, i] all being 1s.
//
//dp[0] = x_0 - y_0
//
//dp[1] = x(f(y_1)) - y(f(y_1)) + dp[f(y(1))]


// dp[n] = x(f(y_n)) - y(f(y_n)) + dp[f(y(n))]
//
//
//
//


long long MOD = 998244353;

int main() {
	int n;
	cin >> n;
	vector<long long> x(n + 1), y(n + 1), a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> a[i];
	}
	vector<long long> dp(n + 1, 0);
	vector<long long> ps(n + 1, 0);
	dp[0] = 0;
	dp[1] = x[1] - y[1];
	ps[1] = dp[1];
	for (int i = 2; i <= n; i++) {
		int ind = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
		// cout << i << " " << ind << endl;
		if (ind == i) {
			dp[i] = x[i] - y[i];
		} else {
			dp[i] = x[i] - y[i] + ps[i - 1] - ps[ind - 1];
		}
		dp[i] = (dp[i] + 10 * MOD) % MOD;
		ps[i] = ps[i - 1] + dp[i];
		ps[i] %= MOD;

	}

	
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res += x[i] - x[i - 1];
		if (a[i] == 1) {
			res += dp[i];
		}
		res %= MOD;
	}
	cout << (res + 1) % MOD << endl;

	return 0;
}
