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
 
 
long long MOD = 1e9 + 7;
 
bool dfs(int ind, long long cur, map<long long, long long> & vis, vector<vector<pair<long long, long long> > > & e, long long h) {
	if (vis.count(ind)) {
		if (cur % h != vis[ind] % h) {
			return false;
		} else {
			return true;
		}
	}
	vis[ind] = cur;
	bool res = true;
	for (int i = 0; i < e[ind].size(); i++) {
		res &= dfs(e[ind][i].first, (cur + e[ind][i].second + h) % h, vis, e, h);
	}
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m, h;
		cin >> n >> m >> h;
 
		long long res = 1;
		vector<vector<long long > > v(n, vector<long long>(m));
 
		vector<vector<pair<long long, long long>> > e(m);
		for (int i = 0; i < n; i++) {
			int f = -1;
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				if (f == -1 && v[i][j] != -1) {
					f = j;
				}
				if (v[i][j] != -1) {
					e[f].push_back({j, (v[i][j] - v[i][f] + h) % h});
					e[j].push_back({f, (v[i][f] - v[i][j] + h) % h});
				}
			}
		}
		map<long long, long long> vis;
		int cnt = 0;
		bool can = true;
		for (int j = 0; j < m; j++) {
			if (!vis.count(j)) {
				cnt++;
				can &= dfs(j, (long long)0, vis, e, h);
			}
		}
		if (!can) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			bool b = true;
			for (int j = 0; j < m; j++) {
				if (v[i][j] != -1) {
					b = false;
					break;
				}
			}
			if (b) cnt++;
		}
		for (int i = 0; i < cnt - 1; i++) {
			res *= h;
			res %= MOD;
		}
		cout << res << endl;
 
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}