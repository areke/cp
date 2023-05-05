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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		long long p;
		cin >> n >> m >> p;
		vector<vector<int> > v(n);
		vector<vector<long long> > vw(n);
		vector<long long> w(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			v[a].push_back(b);
			vw[a].push_back(c);
		}
		vector<vector<long long> > dp(n, vector<long long>(n, -1));
		priority_queue<array<long long, 4> > pq;
		pq.push({0, p, 0, 0});
		while (!pq.empty()) {
			array<long long, 4> t = pq.top();
			pq.pop();
			if (dp[t[2]][t[3]] != -1) {
				continue;
			}
			dp[t[2]][t[3]] = -t[0];
			//cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << endl;
			for (int i = 0; i < v[t[2]].size(); i++) {
				array<long long, 4> next = {t[0], t[1] - vw[t[2]][i], v[t[2]][i], t[3]};
				//cout << t[0] << " " << t[2] << " " << v[t[2]][i] << " " << t[1] << " " << next[1] << endl;
				if (next[1] < 0) {
					next[0] -= abs(next[1]) / w[t[3]];
					next[1] += abs(next[1]) / w[t[3]] * w[t[3]];
					if (next[1] < 0) {
						next[0]--;
						next[1] += w[t[3]];
					}
				}
				//cout << next[0] << endl;
				if (w[t[3]] < w[next[2]]) {
					next[3] = next[2];
				}
				pq.push(next);
			}
		}
		long long BAD = 1e18;
		long long res = BAD;
		for (int i = 0; i < n; i++) {
			if (dp[n - 1][i] != -1) res = min(res, dp[n - 1][i]);
		}
		if (res == BAD) {
			cout << -1 << endl;
		} else {
			cout << res << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
