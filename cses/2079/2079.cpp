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

int dfs(int x, vector<vector<int> > & v, vector<int> & c, int last) {
	c[x] = 1;
	for (int n : v[x]) {
		if (n == last) continue;
		c[x] += dfs(n, v, c, x);
	}
	return c[x];
}

int get_centroid(int x, vector<vector<int> > & v, vector<int> & c, int last) {
	for (int n : v[x]) {
		if (n == last) continue;
		if (c[n] > v.size() / 2) return get_centroid(n, v, c, x);
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> c(n, 0);
	dfs(0, v, c, -1);
	cout << get_centroid(0, v, c, -1) + 1 << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
