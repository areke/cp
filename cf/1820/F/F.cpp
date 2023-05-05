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
	for (int test = 1; test <= tests; test++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > v(n);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			v[i].resize(k);
			for (int j = 0; j < k; j++) {
				cin >> v[i][j];
			}

		}
		// check for all previous with can[i] = true if sum can be 2 for one element, and sum before < 2 for everything else
		int p = 0;
		vector<bool> can(n + 1, 0);
		can[0] = true;
		map<int, int> l;
		int maxi = 0;
		int z = 0;
		bool hasOne = false;
		vector<int> cans = {0};
		int cur = 0;
		map<int, vector<int> > kinds;
		for (int i = 0; i < n; i++) {
			for (int j : v[i]) {
				kinds[j].push_back(i);
			}
			if (v[i].empty()) kinds[0].push_back(i);
		}
		for (int i = 0; i < n; i++) {
			// we know sum([p, i]) < 2 for everything
			// need to know if for any i with can[i] = true in this range, 
			if (cur < cans.size()) {
				int small = cans[cur];
				auto zit = lower_bound(kinds[0].begin(), kinds[0].end(), small);
				for (int j : v[i]) {
					auto it = lower_bound(kinds[j].begin(), kinds[j].end(), small);
					if (it != kinds[j].end()) {
						if ((*it) < i) can[i + 1] = true;
					}
					if (zit != kinds[0].end()) {
						if ((*zit) < i) can[i + 1] = true;
					}
				}
				if (v[i].empty()) {
					if (i - small + 1 > 1) {
						can[i + 1] = true;
					}
				}
			}
			if (can[i + 1]) {
				cans.push_back(i + 1);
			}
			for (int j : v[i]) {
				l[j]++;
				while (l[j] >= 2) {
					for (int k : v[p]) {
						l[k]--;
					}
					p++;
				}
				while (cur < cans.size() && cans[cur] < p) {
					cur++;
				}
			}
		}

		set<int> s;
		int cnt = 0;
		int hz = 0;
		bool pos = true;
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (pos && can[i + 1]) {
				if (hz) {
					res = m;
				} else {
					res = max(res, cnt);
				}
			}
			if (v[i].empty()) {
				hz++;
			}
			for (int j : v[i]) {
				if (s.find(j) != s.end()) {
					pos = false;
				}
				s.insert(j);
				cnt++;
			}
		}
		if (pos) {
			if (hz) {
				res = m;
			} else {
				res = max(res, cnt);
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
