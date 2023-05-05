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
		long long n;
		cin >> n;
		if (n % 2 == 1 && n > 1) {
			cout << -1 << endl;
			continue;
		}
		vector<long long> res(n);
		res[0] = n;
		for (int i = 1; i < n; i++) {
			if (i % 2 == 1) {
				res[i] = n + 1 - res[i - 1];
			} else {
				res[i] = n - i;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
