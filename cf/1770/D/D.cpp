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

long long MOD = 998244353;

void dfs(int x, vector<int> & a, vector<int> & b, set<int> & vis, set<int> & valvis, vector<vector<int> > & v, vector<int> & comp) {
	if (vis.find(x) != vis.end()) return;
	
	vis.insert(x);
	

	comp.push_back(x);
	if (valvis.find(a[x]) == valvis.end()) {
		valvis.insert(a[x]);
		for (int i = 0; i < v[a[x]].size(); i++) {
			if (vis.find(v[a[x]][i]) != vis.end()) continue;
			dfs(v[a[x]][i], a, b, vis, valvis, v, comp);
		}
	}
	if (valvis.find(b[x]) == valvis.end()) {
		valvis.insert(b[x]);
		for (int i = 0; i < v[b[x]].size(); i++) {
			if (vis.find(v[b[x]][i]) != vis.end()) continue;
			dfs(v[b[x]][i], a, b, vis, valvis, v, comp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<vector<int> > v(n + 1);
		for (int i = 0; i < n; i++) {
			v[a[i]].push_back(i);
			v[b[i]].push_back(i);
		}
		vector<vector<int> > components;
		set<int> vis;
		set<int> valvis;
		for (int i = 0; i < n; i++) {
			vector<int> comp;
			if (vis.find(i) == vis.end()) {
				dfs(i, a, b, vis, valvis, v, comp);
				components.push_back(comp);
			}
		}
		long long res = 1;
		//cout << components.size() << endl;
		for (int i = 0; i < components.size(); i++) {	
			set<int> num;
			int same = 0;
			for (int j = 0; j < components[i].size(); j++) {
				//cout << components[i][j] << " ";
				num.insert(a[components[i][j]]);
				num.insert(b[components[i][j]]);
				if (a[components[i][j]] == b[components[i][j]]) {
					same++;
				}
			}
			//cout << same << " " << res << endl;
			if (num.size() == components[i].size()) {
				if (same) {
					for (int j = 0; j < same; j++) {
						res *= n;
						res %= MOD;
					}
				} else {
					res *= 2;
					res %= MOD;
				}
			} else {
				res = 0;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
