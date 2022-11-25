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

// n = 2, answer = x
// n = 3, can all be within 2, or two = and third is smaller.

long long dp[501][501];

long long nCr[501][501];

long long MOD = 998244353;


// 1
// 1 1
// 1 2 1
// 1 3 3 1

long long choose(long long n, long long k) {
	if (k > n) return 0;
	if (k == 0) return 1;
	if (nCr[n][k]) return nCr[n][k];
	long long res = choose(n - 1, k) + choose(n - 1, k - 1);
	res %= MOD;
	nCr[n][k] = res;
	return res;
}

long long modpow(long long n, long long p) {
	if (p == 0) return 1;
	if (n == 0) return 0;
	long long res = modpow(n, p / 2);
	res = res * res % MOD;
	if (p % 2 == 1) {
		res = res * n % MOD;
	}
	return res;
}

long long solve(int n, int x) {
	if (n > x) return modpow(x, n);
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (dp[n][x]) return dp[n][x];
	long long res = 0;
	//cout << n << " " << x << endl;
	for (int i = 0; i <= n; i++) {
		// cout << modpow(min(x, n - 1), i) << " " << choose(n, i) << " " << endl;
		long long cur = choose(n, i) * modpow(min(x, n - 1), i) % MOD;
	//	cout << n << " " << x << " " << i << " " << cur << endl;
		cur = cur * solve(n - i, x - (n - 1)) % MOD;
		res = (res + cur) % MOD;
	}
	dp[n][x] = res;
	return dp[n][x];
}



int main() {
	// for n > x, ans = x^n 
	// for n <= x, same problem with n' <= n and x' = x - (n - 1)
	//
	//
	//
	
	for (int i = 0; i < 501; i++) {
		nCr[i][0] = 1;
		nCr[i][1] = i;
	}

	for (int i = 1; i <= 500; i++) {
		dp[2][i] = i;
	}
	
	int n, x;
	cin >> n >> x;

	cout << solve(n, x) << endl;

}
