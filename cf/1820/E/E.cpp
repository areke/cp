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

 void dfs(int x, vector<vector<int> > & v, vector<int> & d, int last = -1) {
	if (last == -1) d[x] = 1;
	else d[x] = d[last] + 1;
	for (int n : v[x]) {
		if (n == last) continue;
		dfs(n, v, d, x);
	}
 }

 void dfs2(int x, int b, vector<vector<int> > & v, vector<int> & d, vector<int> & p, int last = -1) {
	p.push_back(x);
	if (x == b) {
		d = p;
	}
	for (int n : v[x]) {
		if (n == last) continue;
		dfs2(n, b, v, d, p, x);
	}
	p.pop_back();
 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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
	vector<int> d(n, 0);
	dfs(0, v, d);
	int a = max_element(d.begin(), d.end()) - d.begin();
	fill(d.begin(), d.end(), 0);
	dfs(a, v, d);
	int b = max_element(d.begin(), d.end()) - d.begin();
	vector<int> diam, p;
	dfs2(a, b, v, diam, p);
	set<int> ds;
	for (int x : diam) ds.insert(x);
	vector<int> res;
	bool can = true;
	for (int i = 0; i < diam.size(); i++) {
		if (i % 2 == 0) {
			res.push_back(diam[i]);
		} else {
			for (int x : v[diam[i]]) {
				if (!ds.count(x)) {
					res.push_back(x);
					if (v[x].size() > 1) can = false;
				}
			}
		}
	}
	for (int i = diam.size() - 1; i >= 0; i--) {
		if (i % 2 == 1) {
			res.push_back(diam[i]);
		} else {
			for (int x : v[diam[i]]) {
				if (!ds.count(x)) {
					res.push_back(x);
					if (v[x].size() > 1) can = false;
				}
				
			}
		}
		
	}
	if (can) {
		cout << "Yes" << endl;
		assert(res.size() == n);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] + 1 << " \n"[i == n - 1];
		}
	} else {
		cout << "No" << endl;
	}



	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
