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


struct DSUrb {
	int comp = 0;
	vector<int> e; void init(int n) { e = vector<int>(n,-1); comp = n; }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,5> > mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) { mod.push_back({-1,-1,-1,-1, 0}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		comp--;
		mod.push_back({x,y,e[x],e[y], 1});
		e[x] += e[y]; e[y] = x; return 1;
	}
	int components() {
		return comp;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		comp += a[4];
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

void solve(int l, int r, vector<vector<int> > & v, DSUrb & dsu, vector<int> & res) {
	if (l > r) return;
	if (l == r) {
		res[l] = dsu.components();
		return;
	}
	
	int mid = (l + r) / 2;
	int cnt = 0;
	for (int i = mid + 1; i <= r; i++) {
		if (v[i][0] == 1 && v[i][3] <= l) {
			dsu.unite(v[i][1], v[i][2]);
			cnt++;
		}
	}
	solve(l, mid, v, dsu, res);
	for (int i = 0; i < cnt; i++) {
		dsu.rollback();
	}
	cnt = 0;
	for (int i = l; i <= mid + 1; i++) {
		if (v[i][0] == 0 && v[i][4] > r) {
			dsu.unite(v[i][1], v[i][2]);
			cnt++;
		}
	}
	solve(mid + 1, r, v, dsu, res);
	for (int i = 0; i < cnt; i++) {
		dsu.rollback();
	}
	
}

int main() {
	ifstream fin("connect.in");
	ofstream fout("connect.out");

	int n, k;
	fin >> n >> k;

	vector<vector<int> > v;
	vector<int> q;
	map<pair<int, int>, int> last;
	for (int i = 0; i < k; i++) {
		char t;
		fin >> t;
		if (t == '+') {
			int x, y;
			fin >> x >> y;
			x--;
			y--;
			last[{x, y}] = v.size();
			
			v.push_back({0, x, y, (int)v.size(), (int)1e9});
		} else if (t == '-') {
			int x, y;
			fin >> x >> y;
			x--;
			y--;
			v[last[{x, y}]][4] = v.size(); 
			v.push_back({1, x, y, (int)last[{x,y}], (int)v.size()});
			last.erase(last.find({x,y}));
		} else {
			q.push_back(v.size());
		}
	}	

	vector<int> res(v.size(), 0);
	DSUrb dsurb;
	dsurb.init(n);
	solve(0, v.size() - 1, v, dsurb, res);
	for (int i = 0; i < q.size(); i++) {
		if (q[i] == 0) {
			fout << n << endl;
		} else {
			fout << res[q[i] - 1] << endl;
		}
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
