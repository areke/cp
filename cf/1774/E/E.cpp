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
#include <unordered_set>
#include <array>
#include <cstring>
using namespace std;



int n, d;
vector<vector<int> >  e;
vector<bool> vis;

int calc(int x, vector<bool> & a, vector<bool> & b, int cnt, int & res, int d) {
	if (vis[x]) return {0};
	vis[x] = true;
	if (!a[x]) return {0};
	if (!b[x]) cnt++;
	if (x != 0) res++;
	//cout << x << " " << res << " " << cnt << endl;
	int m = 1;
	for (int &n : e[x]) {
		m = max(m,  1 + calc(n, a, b, cnt, res, d));
	}
	if (m > d && !b[x]) res++;
	return m;
}

void dfs(int x, vector<bool> & s, vector<bool> & f, unordered_set<int> & cur) {
	if (vis[x]) return;
	vis[x] = true;
	cur.insert(x);
	if (s[x]) {
		for (int a : cur) {
			f[a] = true;
		}
		cur = {};
	}
	for (int &n : e[x]) {
		dfs(n, s, f, cur);
	}
	if (cur.find(x) != cur.end()) cur.erase(cur.find(x));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		// dfs to find each tree
		// dfs again and if exit the other tree increment a count
		// if count exceeds d, increment some extra var by 1
		// return sum of tree distances *2 + extra var * 2

		cin >> n >> d;
		e.resize(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int a;
		cin >> a;
		vector<bool> as(n, false);

		vector<bool> bs(n, false);

		vector<bool> bset(n, false);
		vector<bool> aset(n, false);
		vis.assign(n, false);

		unordered_set<int> cur;
		int b;
		for (int i = 0; i < a; i++) {
			int x;
			cin >> x;
			x--;
			as[x] = true;
		}
		cin >> b;
		for (int i = 0; i < b; i++) {
			int x;
			cin >> x;
			x--;
			bs[x]= true;
		}
		//cout << "WHAT" << endl;
		//cout << "HUH" << endl;
		dfs(0, as, aset, cur);
		vis.assign(n, false);
		cur = {};
		dfs(0, bs, bset, cur);
		vis.assign(n, false);
		int res = 0;
		//cout << aset.size() << " " << bset.size() << endl;
		calc(0, aset, bset, 0, res, d);
		vis.assign(n, false);
		calc(0, bset, aset, 0, res, d);
		cout << res * 2 << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
