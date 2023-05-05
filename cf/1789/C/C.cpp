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
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long res = 0;
		map<int, long long> ma;
		for (int i = 0; i < n; i++) {
			ma[a[i]] = -1;
		}
		vector<long long> d(m + 1, 0);
		vector<long long> dp(m + 1, 0); 
		map<int, long long> dif;
		
		for (int i = 1; i <= m; i++) {
			long long p, v;
			cin >> p >> v;
			p--;
			ma[a[p]] = i - 1;
			long long last = -1;
			if (ma.count(v)) {
				last = ma[v];
			}
			// m has last time v appeared
			// how many different + i - v - 1

			// d has how many are different from the ith val
			long long ld = dif[v];
			
			d[i] = ld + i - last - 1;
			dif[v] = d[i];
			dp[i] = dp[i - 1] + d[i] - dif[a[p]];
			res += dp[i];
			
			//cout << i << " " << d[i] << " " << dp[i] << " " << p << " " << v << " " << a[p] << " " << ld << " " << last << endl;
			a[p] = v;
		}
		res += m * (m + 1) / 2 * n;
		cout << res << endl;
		//cout << "-----" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
