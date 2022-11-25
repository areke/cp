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
#include <tuple>
using namespace std;

int solve(int o, int e, int t, int s, map<tuple<int, int, int, int>, int> & dp, map<tuple<int, int, int, int>, bool> & vis) {
	if (o == 0 && e == 0) {

		return s;
	}
	if (vis[tuple(o, e, t, s)]) return dp[tuple(o, e, t, s)];
	int res;
	if (t == 0) {
		res = 1;
		if (o) {
			res = min(res, solve(o-1, e, t ^ 1, s ^ 1, dp, vis));
		}
		if (e) {
			res = min(res, solve(o, e - 1, t ^ 1, s, dp, vis));
		}
	} else {
		res = 0;
		if (o) {
			res = max(res, solve(o - 1, e, t ^ 1, s, dp, vis));
		}
		if (e) {
			res = max(res, solve(o, e - 1, t ^ 1, s, dp, vis));
		}
	}
	dp[tuple(o, e, t, s)] = res;
	vis[tuple(o, e, t, s)] = true;
	return res;
}
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		int evens = 0;
		int odds = 0;
		for (int i = 0; i < n; i++) {
			long long a;
			cin >> a;
			if (a % 2) odds++;
			else evens++;
		}
		map<tuple<int, int, int, int>, int> dp;
		map<tuple<int, int, int, int>, bool> vis;
		int res = solve(odds, evens, 0, 0, dp, vis);
		if (res == 0) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}
