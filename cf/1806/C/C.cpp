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
		int n;
		cin >> n;
		vector<long long> v(2 * n);
		vector<long long> c(2 * n);
		long long mini = 1e18;
		for (int i = 0; i < 2 *n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		if (n == 1) {
			long long res = 0;
			for (int i = 0; i < 2 * n; i++) {
				res += abs(v[i] - v[0]); 
			}
			cout << res << endl;
			continue;
		} else if (n == 2) {
			for (int i = 0; i < 2 * n; i++) {
				c[i] = 2;
			}
			long long cur = 0;
			for (int i = 0; i < 2 * n; i++) {
				cur += abs(v[i] - c[i]);
			}
			mini = cur;
		}
		for (int i = 0; i < 2 * n; i++) {
			c[i] = 0;
		}
		long long cur = 0;
		for (int i = 0; i < 2 * n; i++) {
			cur += abs(v[i] - c[i]);
		}
		if (cur < mini) {
			mini = cur;
		}
		cur = 0;
		if (n % 2 == 0) {
			for (int i = 0; i < 2 * n - 1; i++) {
				c[i] = -1;
			}
			c[2 * n - 1] = n;
			for (int i = 0; i < 2 * n; i++) {
				cur += abs(v[i] - c[i]);
			}
			if (cur < mini) {
				mini = cur;
			}
		}
		cout << mini << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
