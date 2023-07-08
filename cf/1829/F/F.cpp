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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int c = -1;
		for (int i = 0; i < n; i++) {
			bool can = v[i].size() != 1;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[v[i][j]].size() == 1 ) can = false;
			}
			if (can) c = i;
		}
		assert(c != -1);
		int x = v[c].size();
		int y;

		for (int i = 0; i < n; i++) {
			if (v[i].size() == 1) {
				y = v[v[i][0]].size() - 1;
				break;
			}
		}
		cout << x << " " << y << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
