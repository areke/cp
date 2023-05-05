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
#include <unordered_set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
int cnt = 0;


int solve(int x, int d, vector<vector<int> > & v, unordered_set<int> & cur, vector<int> & dp, int & res, unordered_set<int> & vis) {
	if (vis.find(x) != vis.end()) return 1e8;
	vis.insert(x);
	if (dp[x] <= d) return dp[x];
	if (cur.find(x) != cur.end()) {
		res = min(res, d);
		return dp[x] = 0;
	}
	if (d >= res - 1) return dp[x];
	int old = dp[x];
	dp[x] = d;
	int best = 1e8;
	for (int i = 0; i < v[x].size(); i++) {
		best = min(best, 1 + solve(v[x][i], d + 1, v, cur, dp, res, vis));
	}
	res = min(res, d + best);
	//cout << x << " " << d << " " << best << endl;
	
	return old;
}

int solve2(int x, int d, vector<vector<int> > & v, unordered_set<int> & cur, vector<int> & dp, vector<int> & vis) {
	cnt++;
	assert(cnt <= 9e8);
	if (vis[x]) return 1e8;
	vis[x] = 1;
	if (cur.find(x) != cur.end()) {
		d = 0;
	}
	int old = dp[x];
	dp[x] = min(d, dp[x]);
	int best = 1e8;
	for (int i = 0; i < v[x].size(); i++) {
		best = min(best, 1 + solve2(v[x][i], d + 1, v, cur, dp, vis));
	}
	//cout << x << " " << d << " " << best << endl;
	return old;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, x;
		cin >> n >> x;
 
		vector<int> c;
		x--;
		c.push_back(x);
		for (int i = 0; i < n - 1; i++) {
			cin >> x;
			x--;
			c.push_back(x);
		}
		vector<vector<int> > v(n);
		for (int i = 0; i < n -1; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		unordered_set<int> s;
		vector<int> res(n - 1, 1e6);
		int cur = n;
		vector<int> dp(n, 1e9);
		vector<int> vis1(n, 0);
		int border = min((int)c.size() - 1, (int)sqrt(c.size()) + 1);
		for (int i = 0; i <= border; i++) {
			vis1.assign(n, 0);
			cur = min(cur, solve2(c[i], 0, v, s, dp, vis1));
			if (i > 0) {
				res[i - 1] = cur;
			}
			s.insert(c[i]);
		}
		for (int i = 0; i < n; i++) {
			assert(dp[i] <= border + 1);
		}
		for (int i = border + 1; i < c.size(); i++) {
			int next = cur;
			unordered_set<int> vis;
			next = min(next, solve(c[i], 0, v, s, dp, next, vis));
			res[i - 1] = next;
			cur = next;
			s.insert(c[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			cout << res[i];
			if (i == n - 2) cout << endl;
			else cout << " ";
		}
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}