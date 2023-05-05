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
		int n, k, d, w;
		cin >> n >> k >> d >> w;
		vector<int> v(n);
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int end = -1;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (cur == 0) {
				end = v[i] + w + d;
				res++;
			}
			if (v[i] <= end) {
				cur++;
			} else {
				cur = 1;
				res++;
				end = v[i] + w + d;
			}
			cur %= k;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;

}