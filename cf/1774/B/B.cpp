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
		long long n, m, k;
		cin >> n >> m >> k;
		vector<long long> a(m);
		bool can = true;
		long long mod = n % k;
		long long cnt = 0;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			long long t = n / k;
			if (a[i] <= t) continue;
			if (mod != 0) t++;
			if (a[i] == t) cnt++;
			else {
				can = false;
			}
		}
		if (can && cnt <= mod) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
