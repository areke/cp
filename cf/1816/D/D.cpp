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

void dfs(int x, vector<vector<int> > & v, set<int> & vis, vector<int> & order) {
	if (vis.find(x) != vis.end()) return;
	order.push_back(x);
	vis.insert(x);
	for (int n : v[x]) {
		dfs(n, v, vis, order);
	}
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << "! 1 2 2 1" << endl;
			int ans;
			cin >> ans;
			continue;
		}
		int q;
		cout << "+ " << n << endl;
		cin >> q;
		cout << "+ " << n + 1 << endl;
		cin >> q;
		vector<int> res(n + 1, 0);
		vector<int> o;
		vector<vector<int> > v(n + 1);
		for (int i = 1; i <= n - 1; i++) {
			v[i].push_back(n - i);
		}
		for (int i = 1; i <= n; i++) {
			v[i].push_back(n + 1 - i);
		}
		set<int> vis;
		dfs(n, v, vis, o);
		vector<int> d(n + 1, 0);
		int maxi = 0;
		int first = 1;
		for (int i = 2; i <= n; i++) {
			cout << "? " << 1 << " " << i << endl; 
			cin >> d[i];
			maxi = max(maxi, d[i]);
			if (d[i] == maxi) {
				first = i;
			}
		}
		vector<int> line(n);
		line[0] = first;
		for (int i = 1; i <= n; i++) {
			if (i == first) continue;
			cout << "? " << first << " " << i << endl;
			int dist;
			cin >> dist;
			line[dist] = i;
		}

		
		for (int i = 0; i < n; i++) {
			res[line[i]] = o[i];
		}
		cout <<"! ";
		for (int i = 1; i <= n; i++) {
			cout << res[i] << " ";
		}
		for (int i = 0; i < n; i++) {
			res[line[i]] = o[n - i - 1];
		}

		
		for (int i = 1; i <= n; i++) {
			cout << res[i];
			if (i == n) cout << endl;
			else cout << " ";
		}
		int ans;
		cin >> ans;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
