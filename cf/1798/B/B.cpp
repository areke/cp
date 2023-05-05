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
		int m;
		cin >> m;
		vector<vector<int> > v(m);
		map<int, int> cnt;
		for (int i = 0; i < m; i++) {
			int n;
			cin >> n;
			v[i].resize(n);
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		bool can = true;
		vector<int> winners(m);
		for (int i = m - 1; i >= 0; i--) {
			bool b = false;
			for (int j = 0; j < v[i].size(); j++) {
				//cout << i << " " << j << " " << v[i][j] << " " << cnt[v[i][j]] << endl;
				
				if (cnt[v[i][j]] == 0) {
					
					winners[i] = v[i][j];
					b = true;
				}
				cnt[v[i][j]]++;
			}
			if (!b) {
				can = false;
				break;
			}
		}
		if (!can) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < m; i++) {
				cout << winners[i];
				if (i == m - 1) cout << endl;
				else cout << " ";
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
