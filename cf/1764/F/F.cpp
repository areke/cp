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

struct edge {
	long long x, y, d;
	edge(long long x, long long y, long long d) {
		this->x = x;
		this->y = y;
		this->d = d;
	}

	bool operator<(const edge & e) const {
		return d < e.d;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<vector<long long> > f(n, vector<long long>(n, 0));
		
		priority_queue<edge> pq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				long long x;
				cin >> x;
				f[i][j] = x;
				f[j][i] = x;
				if (i != j) pq.push(edge(i, j, f[i][j]));
			}
		}
		DSU dsu(n);
		vector<edge> v;
		while (!pq.empty()) {
			edge e = pq.top();
			pq.pop();
			if (!dsu.same_set(e.x, e.y)) {
				dsu.unite(e.x, e.y);
				v.push_back(e);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			long long w = (f[v[i].x][v[i].x] + f[v[i].y][v[i].y] - 2 * f[v[i].x][v[i].y]) / n;
			cout << v[i].x + 1 << " " << v[i].y + 1 << " " << w << endl;
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
