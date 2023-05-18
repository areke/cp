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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

const int LEVELS = 19;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	vector<int> cnt(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
		cnt[v[i]]++;
	}
	vector<int> d(n, 0);
	vector<int> c(n, 0);
	vector<bool> vis(n, 0);
	queue<int> qq;
	for (int i = 0; i < n; i++) {
		if (!cnt[i]) {
			qq.push(i);
		}
	}
	vector<int> rev;
	while (!qq.empty()) {
		int t = qq.front();
		qq.pop();
		cnt[v[t]]--;
		rev.push_back(t);
		if (!cnt[v[t]]) qq.push(v[t]);
	}
	
	for (int i = rev.size() - 1; i >= 0; i--) {
		d[rev[i]] = d[v[rev[i]]] + 1;
	}
	DSU dsu(n);
	DSU dsu2(n);
	for (int i = 0; i < n; i++) {
		dsu2.unite(i, v[i]);
	}
	
	for (int i = 0; i < n; i++) {
		if (!d[i] && !c[i]) {
			int cnt = 1;
			int x = v[i];
			while (x != i) {
				x = v[x];
				cnt++;
			}
			x = v[i];
			c[x] = cnt;
			while (x != i) {
				dsu.unite(x, v[x]);
				x = v[x];
				c[x] = cnt;
			}
		}
	}

	for (int i = rev.size() - 1; i >= 0; i--) {
		c[rev[i]] = c[v[rev[i]]];
	}

	vector<int> a(n, 0);
	vector<int> cmp(n, 0);

	vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
	jump[0] = v;
	int comp = 1;
	for (int i = 0; i < n; i++) {
		if (!cnt[i]) {
			set<int> s;
			cmp[i] = comp;
			int x = i;
			while (v[x] != -1 && s.find(v[x]) == s.end() && !a[v[x]]) {
				s.insert(x);
				if (!a[v[x]]) {
					a[v[x]] = a[x] + 1;
				}
				if (!cmp[v[x]]) cmp[v[x]] = comp;
				x = v[x];
			}
			comp++;
			v[x] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!a[i]) {
			set<int> s;
			cmp[i] = comp;
			int x = i;
			while (v[x] != -1 && s.find(v[x]) == s.end() && !a[v[x]]) {
				s.insert(x);
				if (!a[v[x]]) {
					a[v[x]] = a[x] + 1;
				}
				if (!cmp[v[x]]) cmp[v[x]] = comp;
				x = v[x];
			}
			comp++;
			v[x] = -1;
		}
	}


	for (int i = 1; i < jump.size(); i++) {
		for (int j = 0; j < n; j++) {
			auto old = jump[i - 1][j];
			if (old == -1) continue;
			auto next = jump[i - 1][old];
			jump[i][j] = next;
		}
	}
	auto jmp = [&](int x, int d) {
		int ret = x;
		for (int i = 0; i < LEVELS; i++) {
			if ((1 << i) & d) {
				ret = jump[i][x];
				x = jump[i][x];
			}
			if (x == -1) return -1;
		}
		return ret;
	};


	for (int qn = 0; qn < q; qn++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if ((!dsu.same_set(jmp(x, d[x]), jmp(y, d[y]))) || d[y] > d[x]) {
			cout << -1 << endl;
			continue;
		}
		if (!d[x] && !d[y]) {
			if (!dsu.same_set(x, y)) {
				cout << -1 << endl;
			} else {	
				cout << (a[y] - a[x] + c[x]) % c[x] << endl;
			} 
		} else if (d[x] && d[y]) {

			if (jmp(x, d[x] - d[y]) != y) {
				cout << -1 << endl;
			}
			else cout << d[x] - d[y] << endl;
		} else if (d[x] && !d[y]) {
			int k = d[x];
			x = jmp(x, d[x]);

			if (dsu.same_set(x, y)){
				k += (a[y] - a[x] + c[x]) % c[x];
				cout << k << endl;
			} else cout << -1 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
