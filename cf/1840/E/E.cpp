#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		vector<string> v(2);
		cin >> v[0] >> v[1];
		int n = v[0].length();
		int t, q;
		cin >> t >> q;
		int cnt = 0;
		queue<pair<int, int> > pq;
		for (int i = 0; i < n; i++) {
			if (v[0][i] != v[1][i]) cnt++;
		}

		for (int i = 0; i < q; i++) {
			while (!pq.empty() && i >= pq.front().first) {
				auto top = pq.front();
				pq.pop();
				if (v[0][top.second] != v[1][top.second]) {
					cnt++;
				}
			}
			int ty;
			cin >> ty;
			if (ty == 1) {
				int p;
				cin >> p;
				p--;
				if (v[0][p] != v[1][p]) {
					cnt--;
				}
				pq.push({i + t, p});
				//cout << i + t << endl;
			} else if (ty == 2) {
				int bef = 0;
				int s1, p1, s2, p2;
				cin >> s1 >> p1 >> s2 >> p2;
				s1--;
				s2--;
				p1--;
				p2--;
				if (v[0][p1] != v[1][p1]) bef--;
				if (v[0][p2] != v[1][p2]) bef--;

				swap(v[s1][p1], v[s2][p2]);
				if (v[0][p1] != v[1][p1]) bef++;
				if (v[0][p2] != v[1][p2]) bef++;
				cnt += bef;
			} else {
				if (cnt) {
					cout << "NO" << endl;
				} else {
					cout << "YES" << endl;
				}
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
