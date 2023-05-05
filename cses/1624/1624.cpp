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

int intersect(int a, int b, int c, int d) {
	return (a == c || b == d || abs(b - d) == abs(a - c));
}

int solve(int x, vector<string> & v, vector<pair<int, int> > & q) {
	if (x >= v.size()) {
		if (q.size() == v.size()) return 1;
		else return 0;
	}
	int res = 0;
	for (int i = 0; i < v[x].size(); i++) {
		bool can = true;
		for (auto y : q) {
			if (intersect(x, i, y.first, y.second)) {
				can = false;
			}
		}
		if (can) {
			if (v[x][i] == '.') {
				q.push_back({x, i});
				res += solve(x + 1, v, q);
				q.pop_back();
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	vector<string> v(8);
	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}
	vector<pair<int, int> > q;
	cout << solve(0, v, q) << endl;




	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
