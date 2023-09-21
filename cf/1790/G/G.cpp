#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		
		int n, m;
		cin >> n >> m;
		int p, bb;
		cin >> p >> bb;
		vector<int> t(n, 0);
		vector<int> b(n, 0);
		for (int i = 0; i < p; i++) {
			int x;
			cin >> x;
			x--;
			t[x] = 1;
		}
		for (int i = 0; i < bb; i++) {
			int x;
			cin >> x;
			x--;
			b[x] = 1;
		}
		vector<vector<int> > v(n);
		vector<int> w(n, 0);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x].push_back(y);
			v[y].push_back(x);
			if (b[x] && b[y]) {
				w[x] = true;
				w[y] = true;
			}
		}
		
		queue<pair<int, int> > q;
		q.push({0, 0});
		vector<int> d(n, 1e9);
		set<int> vis;
		while (!q.empty()) {
			auto [x, dis] = q.front();
			q.pop();
			if (vis.count(x)) continue;
			vis.insert(x);
			d[x] = dis;
			if (!b[x] && x != 0) continue;
			for (int nxt : v[x]) {
				q.push({nxt, dis + 1});
			}
		}
		int moves = 0;
		int winners = 0;

		for (int i = 0; i < n; i++) {
			if (t[i]) {
				bool win = false;
				bool mov = false;
				for (int nxt : v[i]) {
					if (w[nxt]) win = true;
					if (b[nxt]) mov = true;
				}
				if (mov) moves++;
				if (win) winners++;
			}	
		}
		string res = "NO";
		for (int i = 0; i < n; i++) {
			bool can = false;
			bool win = false;
			if (t[i]) {
				for (int nxt : v[i]) {
					if (b[nxt]) can = true;
					if (w[nxt]) win = true;
				}
				if (can) moves--;
				if (win) winners--;
				assert(moves >= 0);
				assert(winners >= 0);
				if (moves + 1 >= d[i] || (winners && d[i] != 1e9)) {
					//cout << i << " " << d[i] << endl;
					res = "YES";
				}
				if (can) moves++;
				if (win) winners++;
			}	
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
