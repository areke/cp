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
#include <array>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, me;
		cin >> n >> me;
		vector<vector<int> > e(n);
		for (int i = 0; i < me; i++) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int f;
		cin >> f;
		vector<int> h(f);
		vector<int> cars(n, 0);
		for (int i = 0; i < f; i++) {
			cin >> h[i];
			h[i]--;
			cars[h[i]]++;
		}
		int k;
		cin >> k;
		vector<int> c(k + 1);
		c[0] = 0;
		//cout << "UH " << n << " " << m << " " << f << " " << k << endl;
		map<int, int> m;
		
		for (int i = 1; i <= k; i++) {
			cin >> c[i];
			c[i]--;
			c[i] = h[c[i]];
			cars[c[i]]--;
			m[c[i]] |= (1 << (i - 1));
		}
		
		vector<long long> costs(n, 1e18);
		queue<array<int, 3> > q;
		q.push({0, 0, m[0]});
		map<int, set<int> > masks;
		vector<vector<int> > vis(n, vector<int>(1 << k, 0));

		while (!q.empty()) {
			array<int, 3> top = q.front();
			q.pop();
			if (vis[top[0]][top[2]]) continue;
			if (costs[top[0]] < top[1]) continue;
			masks[top[0]].insert(top[2]);
			vis[top[0]][top[2]] = 1;
			costs[top[0]] = top[1];
			for (int x : e[top[0]]) {
				q.push({x, top[1] + 1, top[2] | m[x]});
			}
		}
		set<int> res;
		res.insert(0);
		for (int i = 0; i < n; i++) {
			if (!cars[i]) continue;
			for (int jj = 0; jj < cars[i]; jj++) {
				set<int> next;
				for (int j : masks[i]) {
					for (int l : res) {
						next.insert(l | j);
					}
				}
				for (int l : next) {
					res.insert(l);
				}
			}
			
		}
		int ans = k;
		for (int i : res) {
			ans = min(ans, k - __builtin_popcount(i));
		}
		cout << ans << endl;
	}
	return 0;
}
