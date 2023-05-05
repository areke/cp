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

vector<long long> p;
pair<long long, int> dfs(int x, vector<long long> & a, vector<vector<int> > & v, vector<multiset<pair<long long, int> > > & s, vector<pair<long long, int> > & dp, set<int> & vis) {
	vis.insert(x);
	pair<long long, int> res = {a[x], 1};
	for (int n : v[x]) {
		if (vis.find(n) != vis.end()) continue;
		p[n] = x;
		pair<long long, int> val = dfs(n, a, v, s, dp, vis);
		//cout << x << " " << n << " " << val << " " << s[x].size() << endl;
		s[x].insert({val.second, -n});
		//cout << x << " " << n << endl;
		res.first += val.first;
		res.second += val.second;
	}
	//cout << x << " " << res << endl;
	return dp[x] = res;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n);
	vector<long long> a(n);
	for (int i = 0; i< n; i++) {
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
	vector<multiset<pair<long long, int> > > s(n);
	vector<pair<long long, int> > res(n, {0, 0});
	set<int> vis;
	//cout << "HM" << endl;
	dfs(0, a, v, s, res, vis);
	//cout << "?" << endl;
	//cout << "HUH" << endl;
	for (int i = 0; i < m; i++) {
		int t, x;
		cin >> t >> x;
		//cout << i << " " << t << " " << x << endl;
		x--;
		if (t == 1) {
			cout << res[x].first << endl;
		} else {
			if (s[x].empty()) continue;
			pair<long long, int> maxi = *(s[x].rbegin());
			int c = -maxi.second;

			// swap x and c
			
			//cout << "1" << endl;
			pair<long long, int> cur = {res[x].second, -x};
			//cout << cur.first << " " << cur.second << " " << p[x] << endl;
			s[p[x]].erase(s[p[x]].find(cur));
			
			//cout << "2" << endl;
			s[x].erase(s[x].find(maxi));
			
			res[x].first -= res[c].first;
			res[x].second -= res[c].second;
			s[c].insert({res[x].second, -x});

			res[c].first += res[x].first;
			res[c].second += res[x].second;
			//cout << res[c].first << " " << res[c].second << " " << c << " " << p[x] << endl;
			s[p[x]].insert({res[c].second, -c});

			p[c] = p[x];
			p[x] = c;
		}
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
