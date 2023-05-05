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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int l = (n + 1) / 2;
		int r = (n + 2) / 2;
		int lind = -1;
		int rind = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] == l) lind = i;
			if (v[i] == r) rind = i;
		}
		int lcnt = 0;
		int rcnt = 0;
		for (int i = lind + 1; i < n; i++) {
			if (v[i] == lcnt + 1 + l) {
				lcnt++;
			}
		}
		for (int i = rind - 1; i >= 0; i--) {
			if (v[i] == r - rcnt - 1) {
				rcnt++;
			}
		}
		//cout << lind << " " << rind << " " << lcnt << " " << rcnt << endl;
		int exp = n / 2;
		int res = max(exp - lcnt, exp - rcnt);
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
