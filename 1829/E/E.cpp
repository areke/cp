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
vector<vector<int> > dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void dfs(int x, int y, vector<vector<int> > & comp, vector<vector<long long> > & v, int cmp) {
	if (v[x][y] == 0) return;
	if (comp[x][y]) return;
	comp[x][y] = cmp;
	for (auto d : dir) {
		if (d[0] + x >= comp.size() || d[0] + x < 0) continue;
		if (d[1] + y >= comp[0].size() || d[1] + y < 0) continue;
		dfs(d[0] + x , d[1] + y, comp , v, cmp);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<vector<long long> > v(n, vector<long long>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
			}
		}
		vector<vector<int> > comp(n, vector<int>(m, 0));
		int cmp = 1;
		for (int i = 0; i< n; i++) {
			for (int j = 0; j< m; j++) {
				if (v[i][j] && !comp[i][j])  {
					dfs(i, j, comp, v, cmp);
					cmp++;
				}
			}
		}
		map<int, long long> mp;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < m; j++) {
				mp[comp[i][j]] += v[i][j];
			}
		}
		long long res = 0;
		for (auto it : mp) {
			res = max(res, it.second);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
