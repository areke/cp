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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
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
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int uneq = -1;
		for (int i = 0; i < n / 2; i++) {
			if (v[i] != v[n - i - 1]) {
				uneq = i;
			}
		}
		if (uneq == -1) {
			cout << 0 << endl;
			continue;
		}
		long long res = abs(v[uneq] - v[n - uneq - 1]);;
		for (int i = 0; i < n / 2; i++) {
			if (v[i] != v[n - i - 1]) {
				res = gcd(res, abs(v[i] - v[n - i - 1]));
			}
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
