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

int main() {
	long long n, m;
	cin >> n >> m;
	vector<int> primes(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (!primes[i]) {
			primes[i] = 1;
		}
		int k = 2 * i;
		while (k <= n) {
			primes[k] = 2;
			k += i;
		}
	}
	vector<long long> pl;
	for (int i = 2; i <= n; i++) {
		if (primes[i] == 1) pl.push_back(i);
	}

	long long cur = m;
	vector<long long> counts(n);
	long long cp = 0;
	long long MOD = 998244353;
	for (int i = 0; i < n; i++) {
		if (primes[i + 1] == 1) {
			cur = cur / (i + 1);
		}
		counts[i] = cur % MOD;
	}
	long long curres = 1;
	long long curtot = 1;
	long long tot = 0;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		curres *= counts[i];
		curres %= MOD;
		res += curres;
		res %= MOD;
		curtot *= (m % MOD);
		curtot %= MOD;
		tot += curtot;
		tot %= MOD;
	}
	res = (tot - res + MOD) % MOD;
	cout << res << endl;
	return 0;
}
