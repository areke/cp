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

const long long BAD = 1e18;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<long long> > v(n, vector<long long>(n, BAD));
	for (int i = 0; i < m; i++) {
		long long x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		v[x][y] = min(v[x][y], w);
		v[y][x] = min(v[y][x], w);
	}
	for (int i = 0; i < n; i++) {
		v[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = min(v[i][k] + v[k][j], v[i][j]);
			}
		}
	}
	for (int i = 0; i< q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << (v[x][y] == BAD ? -1 : v[x][y]) << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
