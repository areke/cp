#include <bits/stdc++.h>
using namespace std;

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */



unsigned long long B = 31;
unsigned long long B2 = 29;
const long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int k;
	cin  >> k;
	int n = s.length();
	unordered_set<unsigned long long> d;
	for (int i = 0; i < k; i++) {
		string x;
		cin >> x;
		unsigned long long p = 1;
		unsigned long long res = 0;
		for (int j = x.length() - 1; j >= 0; j--) {
			res += p * (x[j] - 'a' + 1);
			p *= B;
		}
		d.insert(res);
	}
	vector<unsigned long long> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i<= n; i++) {
		unsigned long long cur1 = 0;
		unsigned long long p = 1;
		for (int j = i; j >= 1; j--) {
			cur1 += (s[j - 1] - 'a' + 1) * p;
			if (d.count(cur1)) {
				dp[i] += dp[j - 1];
				dp[i] %= MOD;
			}
			p *= B;
			
			
		}
	}
	cout << dp[n] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
