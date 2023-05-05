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
	int n, t;
	cin >> n >> t;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long low = 0;
	long long high = 1e18;
	long long best = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			cur += mid / v[i];
			if (cur >= t) break;
		}
		if (cur >= t) {
			high = mid - 1;
			best = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << best << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
