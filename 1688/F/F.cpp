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


		vector<long long> a(n);
		vector<long long> b(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<long long> e(n + 1, 0);
		for (int i = 0; i < n; i++) {
			e[i + 1] = e[i] + a[i] - b[i];
		}
		vector<vector<int> > v(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		queue<int> q;

		set<int> bad;
		for (int i = 0; i <= n; i++) {
			if (!e[i]) {
				q.push(i);
			} else {
				bad.insert(i);
			}
		}
		int cnt = 0;
		while (!q.empty()) {
			cnt++;
			int x = q.front();

			
			q.pop();
			for (int & j : v[x]) {
				int l = min(x, j);
				int r = max(x, j);
				if (!e[j]) {
					auto it = bad.lower_bound(l);
					for (; it != bad.end();) {
						if (*it > r) break;
						e[*it] = 0;
						q.push(*it);
						it = bad.erase(it);
					}
				}
			}
		}


		if (bad.empty()) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
