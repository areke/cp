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

 
int solve(int x, vector<long long> & b, vector<long long> & a, vector<vector<int> > & v, vector<set<long long> > & s, int last) {
	int res = 0;
	bool found = false;
	for (int n : v[x]) {
		if (n == last) continue;
		res += solve(n, b, a, v, s, x);
		if (s[n].size() > s[x].size()) {
			swap(s[n], s[x]);
		}
		for (long long y : s[n]) {
			if (s[x].find(y ^ a[x]) != s[x].end()) {
				found = true;
			}
		}
		for (long long y : s[n]) {
			s[x].insert(y);
		}
	}
	if (s[x].find(b[x] ^ a[x]) != s[x].end()) found = true;
	s[x].insert(b[x]);
	if (found) {
		s[x].clear();
		res++;
	}
	return res;
}

void dfs(int x, int cur, vector<vector<int> > & v, vector<long long> & b, vector<long long> & a, int last) {
	cur ^= a[x];
	b[x] = cur;
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, cur, v, b, a, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<long long> a(n);
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

	vector<long long> b(n);
	dfs(0, 0, v, b, a, -1);
	vector<set<long long> > s(n);
	

	int res = solve(0, b, a, v, s, -1);
	cout << res << endl;
 
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}