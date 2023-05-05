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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[y].push_back(x);
		}
		
		map<int, vector<int> > ma;
		vector<int> d(n, 1e9);
		set<int> vis;
		queue<pair<int, int> > q;
		q.push({0, 0});
		while (!q.empty()) {
			pair<int, int> top = q.front();
			q.pop();
			if (vis.find(top.first) != vis.end()) continue;
			vis.insert(top.first);
			d[top.first] = min(d[top.first], top.second);
			for (int n : v[top.first]) {
				d[top.first] = min(d[top.first], d[n] + 1);
				q.push({n, top.second + 1});
			}
		}

		if (vis.size() != n) {
			cout << "INFINITE" << endl;
			continue;
		}
		for (int i = 0; i < d.size(); i++) {
			ma[d[i]].push_back(i);
		}
		int maxi = 0;
		for (auto it : ma) {
			maxi = max(maxi, it.first);
		}
		cout << "FINITE" << endl;
		vector<int> res;
		for (int i = 0; i < maxi + 1; i++) {
			for (int j = maxi - i; j <= maxi; j++) {
				for (int k : ma[j]) {
					res.push_back(k + 1);
				}
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i == res.size() - 1) cout << endl;
			else cout << " ";
		}
		


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
