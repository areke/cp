#include <bits/stdc++.h>
using namespace std;

int get(string & s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		res *= 2;
		res += (s[i] - '0');
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		pair<int, int> start = {0, get(s)};
		int MASK = (1 << 10) - 1; 
		vector<array<int, 3> > med(m);
		for (int i = 0; i < m; i++) {
			string a, b;
			int d;
			cin >> d;
			cin >> a >> b;
			med[i] = {d, MASK ^ get(a), get(b)};
		}
		priority_queue<pair<int, int> > q;
		vector<bool> vis((1 << 10) - 1, 0);
		int res = -1;
		q.push(start);
		while (!q.empty()) {
			auto t = q.top();
			q.pop();
			if (vis[t.second]) continue;
			vis[t.second] = true;
			if (t.second == 0) {
				res = -t.first;
				break;
			}
			for (int i = 0; i < m; i++) {
				q.push({t.first - med[i][0], (t.second & med[i][1]) | med[i][2]});
			}
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
