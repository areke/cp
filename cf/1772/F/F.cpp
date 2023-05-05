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
	int tests = 1;
	while (tests--) {
		int n, m, kk;
		cin >> n >> m >> kk;
		vector<vector<vector<int> > > g;
		for (int c = 0; c < kk + 1; c++) {
			vector<vector<int> > v(n, vector<int>(m, 0));
			for (int i = 0; i < n; i++) {
				string s;
				cin >> s;
				for (int j = 0; j < m; j++) {
					v[i][j] = s[j] - '0';
				}
			}
			g.push_back(v);
		}
		vector<pair<int, int> > o;
		for (int i = 0; i < g.size(); i++) {
			int cnt = 0;
			for (int j = 1; j < n - 1; j++) {
				for (int k = 1; k < m - 1; k++) {
					if (g[i][j][k] != g[i][j + 1][k] && g[i][j][k] != g[i][j  - 1][k] && g[i][j][k] != g[i][j][k + 1] && g[i][j][k] != g[i][j][k - 1]) {
						cnt++;
					}
				}
			}
			o.push_back({cnt, i});
		}
		sort(o.begin(), o.end());
		reverse(o.begin(), o.end());
		vector<vector<int> > res;
		cout << o[0].second + 1 << endl;
		for (int i = 1; i < o.size(); i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (g[o[i].second][j][k] != g[o[i - 1].second][j][k]) {
						res.push_back({1, j + 1, k + 1});
					}
				}
			}
			res.push_back({2, o[i].second + 1});
		}

		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j];
				if (j == res[i].size() - 1) cout << endl;
				else cout << " ";
			}
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
