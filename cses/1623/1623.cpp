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
	long long s = 0;
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s += v[i];
	}
	long long res = 1e18;
	for (int i = 0; i < (1 << n); i++) {
		long long c = 0;
		for (int j = 0; j < n; j++) {
			
			if ((1 << j) & i) {
			
				c += v[j];
			}
		}
		res = min(res, abs(s - 2 * c));
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
