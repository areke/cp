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

bool can = true;

void dfs(int x, int c, vector<vector<int> > & v, vector<int> & col, vector<bool> & vis) {
	if (vis[x]) {
		can = can && (col[x] == c);
		return;
	}
	vis[x] = true;
	col[x] = c;
	for (int n : v[x]) {
		dfs(n, c ^ 1, v, col, vis);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	vector<int> col(n, 0);
	vector<bool> vis(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, 0, v, col, vis);
		}
	}
	if (!can) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for (int i = 0; i < n; i++) {
			cout << col[i] + 1 << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
