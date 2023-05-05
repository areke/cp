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

void dfs(int x, int y, vector<string> & v, set<pair<int, int> > & vis) {
	if (vis.find({x, y}) != vis.end())  return;
	vis.insert({x, y});
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (i != 0 && j != 0) continue;
			if (i == 0 && j == 0) continue;
			if (i + x < 0 || i + x >= 2) continue;
			if (j + y < 0 || j + y >= v[0].size()) continue;
			if (v[x + i][y + j] == 'W') continue;
			dfs(x + i, y + j, v, vis);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		vector<string> v(2);
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			cin >> v[i];
		}
		int cnt = 0;
		set<pair<int, int> > vis;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == 'W') continue;
				if (vis.find({i, j}) == vis.end()) {
					dfs(i, j, v, vis);
					cnt++;
				}
			}
		}
		if (cnt != 1) {
			cout << "NO" << endl;
			continue;
		} else {
			int amt = 0;
			int last = -1;
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (v[0][i] == 'B' && v[1][i] == 'B') {
					amt++;
				} else {
					if (last != -1) {
						if (v[0][i] == v[0][last] && amt % 2 != 0) {
							ok = false;
						} else if (v[0][i] != v[0][last] && amt % 2 == 0) {
							ok = false;
						}
					}
					last = i;
					amt = 0;
				}
			}
			if (ok) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
