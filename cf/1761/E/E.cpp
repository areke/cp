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

void dfs(int x, vector<string> & g, set<int> & comp, set<int> & vis) {
	if (vis.find(x) != vis.end()) return;
	vis.insert(x);
	comp.insert(x);
	for (int i = 0; i < g[x].size(); i++) {
		if (g[x][i] == '1') {
			dfs(i, g, comp, vis);
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
		vector<string> g(n);
		// consider graph with X components
		
		// 1. if each component is a clique, choose any vertex
		// 	this will create a component that is not a clique (or fully connect graph if component of size 1 exists)
		// 2. if at least one component is not a clique, consider that component
		// 	a. consider a vertex that is not connected to every other vertex in the component
				// let A be the vertex, and B be the vertex 
		// 		consider the component of B after removing A's edges

		// a connected graph must have a vertex such that removing that vertex
		// and its edges leaves the rest of the graph connected

		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		vector<int> comp;
		map<int, int> m;

		set<int> vis;
		for (int i = 0; i < n; i++) {
			set<int> s;
			if (vis.find(i) != vis.end()) continue;
			dfs(i, g, s, vis);
			comp.push_back(s.size());
			for (int i : s) {
				m[i] = s.size();
			}
		}
		int res = 2;
		if (comp.size() == 1) {
			cout << 0 << endl;
			continue;
		} else {
			for (int i = 0; i < comp.size(); i++) {
				if (comp[i] == 1) res = 1;
			}

		}

		

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
