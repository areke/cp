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
	for (int test = 1; test <= tests; test++) {
		long long n, m, k;
		cin >> n >> m >> k;
		vector<long long> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		long long c = 0;
		long long d = 0;
		bool hc = false;
		bool hd = false;
		for (int i = 0; i < k; i++) {
			if (a[i] / n > 1) {
				if (a[i] / n > 2) hc = true;
				c += a[i] / n;
			}
			if (a[i] / m > 1) {
				if (a[i] / m > 2) hd = true;
				d += a[i] / m;
			}
		}
		if ((c >= m && hc) || (d >= n && hd)) {
			cout << "Yes" << endl;
		}  else if (c >= m && m % 2 == 0) {
			cout << "Yes" << endl;
		} else if (d >= n && n % 2 == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
