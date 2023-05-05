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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > s(n, vector<int>(n, 0));

	vector<vector<int> > dp((1 << n), vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[(1 << i)][i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;;
		s[x][y] = 1;
		s[y][x] = 1;
		dp[(1 << x) | (1 << y)][min(x, y)] = 1;
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (!((1 << j) & i)) continue;
			if ((1 << (j + 1)) > i) continue;
			int x = i ^ (1 << j);
			for (int k = 0; k < n; k++) {
				if (!((1 << k) & x)) continue;
				if (s[k][j]) {
					dp[i][j] |= dp[x][k];
				}
			}
		}
	}
	bool res = false;
	vector<int> rv;
	for (int i = 1; i < (1 << n); i++) {
		bool cycle = false;
		int first = 0;
		for (int k = n - 1; k >= 0; k--) {
			if ((1 << k) & i) {
				first = k;
				break;
			}
		}
		for (int j = 0; j < n; j++) {
			
			if (!dp[i][j]) continue;
			if (!s[first][j]) continue;
			cycle = true;
		}
		
		if (cycle) {
			bool can = true;
			vector<int> v(n);
			for (int j = 0; j < n; j++) {
				if (!((1 << j) & i)) {
					bool found = false;
					for (int k = 0; k < n; k++) {
						if (!((1 << k) & i)) continue;
						if (s[j][k]) { 
							found = true;
							v[j] = k;
						}
					}
					can = can && found;
				}
			}
			if (can) {
				int x = i;
				int last = first;
				res = true;
				while (x) {
					for (int j = 0; j < n; j++) {
						if (dp[x][j] && s[j][last]) {
							assert((1 << j) & x);
							x ^= (1 << j);
							assert(s[last][j]);
							//cout << j << " " << last << endl;
							v[j] = last;
							last = j;
							break;
						}
					}
				}
				rv = v;
				break;
			}
		}
	}
	if (res) {
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++) {
			cout << rv[i] + 1;
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	} else {
		cout << "No" << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
