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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int res = 0;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] == cur + 1) {
				cur++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (p[i] != i + 1) {
				res = (n - cur) / k;
				if ((n - cur) % k != 0) res++;
				break;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
