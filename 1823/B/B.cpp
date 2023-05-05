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
		int n, k;
		cin >> n >> k;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		vector<set<int> > v(k);
		for (int i = 0; i < n; i++) {
			v[i % k].insert(p[i]);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (v[(i - 1) % k].find(i) == v[(i - 1) % k].end()) {
				cnt++;
			}
		}

		if (cnt == 0) {
			cout << 0 << endl;
		} else if (cnt <= 2) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
