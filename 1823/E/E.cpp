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

void dfs(int x, vector<vector<int> > & v, vector<bool> & vis, int & size) {
	if (vis[x]) return;
	vis[x] = true;
	size++;
	for (int n : v[x]) {
		dfs(n, v, vis, size);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<bool> vis(n, 0);
	vector<int> c;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int sz = 0;
			dfs(i, v, vis, sz);
			c.push_back(sz);
		}
	}
	int y = 0;
	for (int x : c) {
		if (x < r + l) y ^= (x / l);
	}

	if (y) {
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
