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
		int n, k;
		cin >> n >> k;
		vector<int> res(n, 0);
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if ((i) * (i + 1) / 2 <= k) {
				t = i;
			}
		}
		int b = t;
		for (int i = 0; i< t; i++) {
			res[i] = 2;
		}
		int l = k - (t * (t + 1) / 2);
		int v = -(2 * t + 1);
		for (int i = 0; i < l; i++) {
			v += 2;
		}
		if (t < n) {
			res[t] = v;
			for (int i = t + 1; i < n; i++) {
				res[i] = -1000;
			}
		}
		for (int i = 0; i< n; i++) {
			cout << res[i];
			if (i == n - 1)cout << endl;
			else cout << " ";
		}


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
