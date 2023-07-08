#include <bits/stdc++.h>
using namespace std;

bool isPal(int x) {
	vector<int> v;
	while (x) {
		v.push_back(x % 10);
		x/= 10;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != v[v.size() - i - 1]) return false;
	}
	return true;
}

const long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	long long n = 4e4 + 5;
	vector<long long> dp(n, 0);
	vector<bool> p(n);
	int cnt = 0;
	set<int> s;
	for (int i = 1; i < n; i++) {
		p[i] = isPal(i);
		if (p[i]) {
			s.insert(i);
		}
	}
	dp[0] = 1;
	for (int x : s) {
		for (int i = 0; i < n; i++) {
			if (i - x >= 0) {
				dp[i] += dp[i - x];
				dp[i] %= MOD;
			}
		}
	}
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long x;
		cin >> x;
		cout << dp[x] << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
