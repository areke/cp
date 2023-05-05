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

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */

const long long MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> twos(n + 1, 0);
		twos[0] = 1;
		for (int i = 1; i <= n; i++) {
			twos[i] = 2 * twos[i - 1];
			twos[i] %= MOD;
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long d = v[j] - v[i];
				int x = lower_bound(v.begin(), v.end(), v[i] - d) - v.begin();
				int ind = lower_bound(v.begin(), v.end(), v[j] + d) - v.begin();
				int y = n - 1 - ind + 1;
				//cout << i << " " << j << " " << x << " " << ind << endl;
				res += twos[x + y];
				res %= MOD;
			}
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
