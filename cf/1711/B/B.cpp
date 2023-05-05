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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int> > v(n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += a[i];
		}
		if (m % 2 == 0) {
			cout << 0 << endl;
			continue;
		}
		int mini = 2e9;
		for (int i = 0; i < n; i++) {
			if (v[i].size() % 2) {
				mini = min(a[i], mini);
			}
		}
		for (int i = 0; i < n; i++) {
			if (v[i].size() % 2) continue;
			for (int j : v[i]) {
				if (v[j].size() % 2 == 0) {
					mini = min(mini, a[i] + a[j]);
				}
			}
		}
		cout << mini << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
