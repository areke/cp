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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			int low = 0;
			int high = i;
			int best = 0;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (i - mid + 1 <= a[mid]) {
					best = i - mid + 1;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
			res[i] = best;
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
