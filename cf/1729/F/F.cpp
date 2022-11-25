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
		string s;
		cin >> s;
		int n = s.length();
		int w, m;
		cin >> w >> m;
		vector<int> pref(n + 1, 0);
		for (int i = 0; i < n; i++) {
			pref[i + 1] = (pref[i] + (s[i] - '0')) % 9;
		}
		map<int, vector<int> > ma;
		for (int i = 0; i + w <= n; i++) {
			int x = (9 + pref[i + w] - pref[i]) % 9;
			if (ma[x].size() < 2) ma[x].push_back(i);
		}
		for (int i = 0; i < m; i++) {
			int l, r, k;
			cin >> l >> r >> k;
			//cout << l << " " << r << " " << res << endl;
			//cout << i << endl;
			int v = (9 + pref[r] - pref[l - 1]) % 9;
			pair<int, int> res = {1e6, 1e6};
			pair<int, int> bad = res;
			for (int j = 0; j < 9; j++) {
				for (int kk = 0; kk < 9; kk++) {
					if ((j * v + kk) % 9 == k) {
						//cout << i << " " << j << " " << kk << endl;
						if (j == kk) {
							if (ma[j].size() == 2) {
								res = min(res, {ma[j][0], ma[j][1]});
							}
						} else {
							if (ma[j].size() && ma[kk].size()) {
								res = min(res, {ma[j][0], ma[kk][0]});
							}
						}
					}
				}
			}
			if (res == bad) {
				cout << -1 << " " << -1 << endl;
			} else {
				cout << res.first + 1<< " " << res.second + 1 << endl;
			}
		}
		
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
