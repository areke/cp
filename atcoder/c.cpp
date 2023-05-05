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

void dfs(int x, int y, set<int> & s, vector<vector<int> > & v, int & res) {
	if (x >= (int)v.size()) return;
	if (y >= (int)v[0].size()) return;
	if (s.find(v[x][y]) != s.end()) return;
	
	if (x == (int)v.size() - 1 && y == (int)v[0].size() - 1) {
		res += 1;
		return;
	}
	s.insert(v[x][y]);
	dfs(x + 1, y, s, v, res);
	dfs(x, y + 1, s, v, res);
	s.erase(s.find(v[x][y]));
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int> > v(h, vector<int>(w, 0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> v[i][j];
		}
	}
	set<int> s;
	int res = 0;
	dfs(0, 0, s, v, res);
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
