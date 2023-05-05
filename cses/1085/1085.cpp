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
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long low = 0;
	long long high = 1e18;
	long long res = -1;
	while (low <= high) {
		long long mid = (low + high) / 2;
		int cnt = 1;
		long long s = a[0];
		bool can = a[0] <= mid;
		for (int i = 1; i < n; i++) {
			if (a[i] > mid) can = false;
			if (s + a[i] > mid) {
				s = a[i];
				cnt++;
			} else {
				s += a[i];
			}
		}

		if (can && cnt <= k) {
			high = mid - 1;
			res = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << res << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
