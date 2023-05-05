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
		vector<long long> a(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			long long c = n / i;
			a[i] = c * (c - 1) / 2;
		}
		long long tot = 0;
		for (int i = 2; i <= n; i++) {
			tot += a[i] / (i - 1) * (i - 1);
			a[i] = a[i] / (i - 1) * (i - 1);
		}
		if (tot < m) {
			cout << -1 << endl;
			continue;
		}
		long long res = 0;
		long long cnt = 0;
		for (int i = n; i >= 2; i--) {
			long long left = (n - cnt);
			long long num = left / i;
			
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
