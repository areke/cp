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

long long MOD = 1e9 + 7;

map<long long, long long> calc;

long long solve(int x, vector<long long> & dp, vector<bool> & v, int t) {
	if (x <= 0) return 1;
	if (calc.count(x)) return calc[x];
	if (!v[x]) return calc[x] = solve(x - 1, dp, v, t) % MOD;
	long long res = 0;
	for (int i = x; i >= max(x - t + 1, 0); i--) {
		int last = i - t;
		if (last < 0) last = -1;
		if (v[i] && dp[last + 1] + 1 == dp[x + 1]) {
			res += solve(i - t, dp, v, t);
			res %= MOD;
		}
	}
	return calc[x] = res % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		cin >> s;
		string t;
		cin >> t;
		calc.clear();
		if (t.size() > s.size()) {
			cout << 0 << " " << 1 << endl;
			continue;
		}
		vector<bool> v(s.size(), false);
		for (int i = 0; i < s.length(); i++) {
			if (i + t.length() - 1 >= s.length()) break;
			bool b = true;
			for (int j = 0; j < t.length(); j++) {
				if (s[i + j] != t[j]) {
					b = false;
					break;
				}
			}
			v[i + t.length() - 1] = b;
		}
		vector<long long> dp(v.size() + 1, 1e9);
		for (int i = 0; i <= t.size() - 1; i++) {
			dp[i] = 0;
		}
		for (int i = t.size() - 1; i < v.size(); i++) {
			if (!v[i]) {
				dp[i + 1] = dp[i];
			}
			else {
				int last = i - t.size();
				for (int j = 0; j < t.size(); j++) {
					if (i + j + 1 > v.size()) break;
					dp[i + j + 1] = min(dp[last + 1] + 1, dp[i + j + 1]);
				}
			}
		}
		cout << dp[v.size()] << " " << solve(v.size() - 1, dp, v, t.size()) << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
