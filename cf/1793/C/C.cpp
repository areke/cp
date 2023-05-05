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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n <= 3) {
			cout << -1 << endl;
			continue;
		}
		int mini = 1;
		int maxi = n;
		int l = 0;
		int r = n - 1;
		while (r - l + 1 > 3 && (a[l] == mini || a[l] == maxi || a[r] == mini || a[r] == maxi)) {
			if (a[l] == mini) {
				l++;
				mini++;
			} else if (a[l] == maxi) {
				l++;
				maxi--;
			} else if (a[r] == mini) {
				r--;
				mini++;
			} else if (a[r] == maxi) {
				r--;
				maxi--;
			}
		}
		if (r - l + 1 <= 3) {
			cout << -1 << endl;
			continue;
		} else {
			cout << l + 1 << " " << r + 1 << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
