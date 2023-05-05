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

vector<int> dpath;
int diam = -1;

void dfs(int x, vector<vector<int> > & v, map<int, int> & m, vector<int> & p) {
	if (m.count(x)) return;
	if (dpath.size()) return;
	p.push_back(x);
	m[x] = p.size();
	if (p.size() == diam) {
		dpath = p;
		p.pop_back();
		return;
	}
	for (int n : v[x]) {
		dfs(n, v, m, p);
	}
	p.pop_back();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
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
		vector<int> p;
		map<int, int> m;
		dfs(0, v, m, p);
		int best = -1;
		for (auto x : m) {
			if (x.second >= m[best]) {
				best = x.first;
			}
		}
		
		
		m.clear();
		dfs(best, v, m, p);
		best = -1;
		for (auto x : m) {
			if (x.second >= m[best]) {
				best = x.first;
			}
		}
		diam = m[best];
		m.clear();
		dfs(best, v, m, p);


		diam = dpath.size();
		vector<int> res(n, n);
		map<int, int> vm1;
		map<int, int> vm2;
		int dd = diam;
		vector<int> dpp = dpath;
		for (int i = 0; i < dpp.size(); i++) {
			if (i == dd / 2) {
				diam = -1;
				dpath.clear();
				dfs(dpp[i], v, vm1, p);
				diam = -1;
				dpath.clear();
				dfs(dpp[dpp.size() - i - 1], v, vm2, p);
			}
		}
		
		vector<pair<int, int> > o;
		for (auto x : vm1) {
				//cout << x.second << " " << x.first << endl;
				o.push_back({x.second, x.first});
			}
		for (auto x : vm2) {
				o.push_back({x.second, x.first});
			}
		set<int> s;
		sort(o.begin(), o.end());
		int ind = o.size() - 1;
		int cur = dpp.size() / 2;
		cur++;
		int start =cur;
		for (int i = dd - 1; i >= 1; i--) {
			while (ind >=0 && o[ind].first >= cur) {
				//cout << o[ind].first << " " << o[ind].second << endl;
				s.insert(o[ind].second);
				ind--;
			}
			cur--;
			res[i - 1] = n - s.size();
			if (s.size()) res[i - 1]++;
		}
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " "; 
		}


		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
