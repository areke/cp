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

const int MAXN = 100000;

map<int, int> s[MAXN + 1];
int c[MAXN + 1];


void solve(int x, vector<int> & a, vector<vector<int> > & v, int last) {
	int res = 0;
	bool f = false;
	int cnt = 0;
	for (int n : v[x]) {
		if (n == last) continue;
		solve(n, a, v, x);
		if (s[x].size() < s[n].size()) {
			swap(s[x], s[n]);	
		}
		for (auto y : s[n]) {
			s[x][y.first] += y.second;
			if (s[x][y.first] > 1) f = true;
		}
		cnt++;
		res += c[n];
	}

	if (s[x].empty()) {
		s[x] = {{a[x], 1}};
		c[x] = 0;
		return;
	}
	
	
	if (f) {
		int maxi = 0;
		for (auto it : s[x]) {
			maxi = max(maxi, it.second);
		}
		map<int, int> m;
		for (auto it : s[x]) {
			if (it.second == maxi) {
				m[it.first] = 1;
			}
		}
		s[x] = m;
		c[x] = res + cnt - maxi;
	} else {
		int maxi = 1;
		c[x] = res + cnt - maxi;

	}
	
}

void dfs(int x, vector<int> & a, vector<int> & b, vector<vector<int> > & v, int last) {
	if (last == -1) {
		b[x] = a[x];
	} else {
		b[x] = b[last] ^ a[x];
	}
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, a, b, v, x);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int> > v(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vector<int> b(n, 0);
	dfs(0, a, b, v, -1);
	solve(0, b, v, -1);
	if (s[0][0]) {
		cout << c[0] << endl;
	} else {
		cout << c[0] + 1 << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
