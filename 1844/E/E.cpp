#include <bits/stdc++.h>
using namespace std;

// after first two rows, each next row must be one of the 2 thats not before it

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
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int> > dr(m, vector<int>(2, 0));
		vector<vector<int> > dl(m, vector<int>(2, 0));

		vector<vector<int> > cdr(n, vector<int>(2, 0));
		vector<vector<int> > cdl(n, vector<int>(2, 0));
		for (int i = 0; i < k; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--;
			b--;
			c--;
			d--;
			if (b + 1 == d) {
				dr[b][a % 2] = 1;
				cdr[a][b % 2] = 1;
			} else {
				dl[b][a % 2] = 1;
				cdl[a][b % 2] = 1;
			}
		}
		bool can = true;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < 2; j++) {
				if (dr[i][j] && dl[i + 1][j]) can = false;	
			}
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
