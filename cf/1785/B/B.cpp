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
		map<char, int> m = {{'w', 0}, {'i', 1}, {'n', 2}};
		map<int, char> r = {{0, 'w'}, {1, 'i'}, {2, 'n'}};
		vector<vector<vector<int> > > v(3, vector<vector<int> >(3));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vector<int> c(3, 0);
			for (int j = 0; j < 3; j++) {
				c[m[s[j]]]++;
			}
			for (int j = 0; j < 3; j++) {
				while (c[j] > 1) {
					for (int k = 0; k < 3; k++) {
						if (c[k] == 0 && c[j] > 1) {
							v[j][k].push_back(i + 1);
							c[k]++;
							c[j]--;
						}
					}
				}
			}
		}
		vector<vector<int > > res;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				while (v[i][j].size() > 0 && v[j][i].size() > 0) {
					res.push_back({v[i][j].back(), i, v[j][i].back(), j});
					v[i][j].pop_back();
					v[j][i].pop_back();
				}
			}
		}
		vector<int> cycle;
		bool has = false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!v[i][j].empty()) {
					has = true;
				}
			}
		}
		if (has) {
			int cur = 0;
			while (cycle.size() < 3) {
				for (int i = 0; i < 3; i++) {
					if (!v[cur][i].empty()) {
						cycle.push_back(i);
						cur = i;
						break;
					}
				}
			}
			for (int i = 0; i < v[cycle[0]][cycle[1]].size(); i++) {
				res.push_back({v[cycle[0]][cycle[1]][i], cycle[0], v[cycle[1]][cycle[2]][i], cycle[1]});
				
			}
			for (int i = 0; i < v[cycle[0]][cycle[1]].size(); i++) {
				res.push_back({v[cycle[1]][cycle[2]][i], cycle[0], v[cycle[2]][cycle[0]][i], cycle[2]});
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i][0] << " " << r[res[i][1]] << " " << res[i][2] << " " << r[res[i][3]] << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
