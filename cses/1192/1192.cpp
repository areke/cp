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

void dfs(int x, int y, vector<string> & v, vector<vector<bool> > & vis) {
	if (v[x][y] == '#') return;
	if (vis[x][y]) return;
	vis[x][y] = true;
	for (auto d : dir) {
		if (d[0] + x >= v.size() || d[0] + x < 0) continue;
		if (d[1] + y >= v[0].length() || d[1] + y < 0) continue;
		dfs(x + d[0], y + d[1], v, vis);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int res = 0;
	vector<vector<bool> > vis(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && v[i][j] == '.') {
				res++;
				dfs(i, j, v, vis);
			}
		}
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
