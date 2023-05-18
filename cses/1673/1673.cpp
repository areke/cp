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

void dfs(int x, vector<vector<int> > & v, vector<bool> & rev) {
	if (rev[x]) return;
	rev[x] = true;
	for (int n : v[x]) dfs(n, v, rev);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long> > > v(n);
	vector<array<long long, 3> > e;
	vector<vector<int> > r(n);

	set<pair<int, int> > es;
	for (int i = 0; i < m; i++) {
		long long x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		v[x].push_back({y, w});
		e.push_back({x, y, w});
		es.insert({x, y});
		r[y].push_back(x);
	}
	vector<bool> vis(n, 0);
	long long BAD = -1e18;
	vector<long long> res(n, BAD);
	res[0] = 0;
	int cur = 0;
	for (int i = 0; i < n - 1; i++) {
		vector<long long> next = res;
		for (auto ed : e) {
			if (res[ed[0]] != BAD) {
				next[ed[1]] = max(res[ed[0]] + ed[2], next[ed[1]]);
			}
		}
		res = next;
	}
	vector<long long> res2 = res;
	vector<long long> next = res2;
	for (auto ed : e) {
		if (res2[ed[0]] != BAD) {
			next[ed[1]] = max(res2[ed[0]] + ed[2], next[ed[1]]);
		}
	}
	res2 = next;
	vector<bool> rev(n);
	dfs(n - 1, r, rev);
	
	for (int i = 0; i < n; i++) {
		if (res[i] != res2[i] && rev[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	long long ans = res[n - 1];
	cout << ans << endl;



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
