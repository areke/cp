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
		cin >> n >> m;
		vector<vector<long long> > a(n, vector<long long> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int low = 1;
		int high = min(n, m);
		int res = 0;
		while (low <= high) {
			int mid = (low + high) / 2;
			vector<vector<long long> > s(n, vector<long long> (m, 0));

			for (int i = 0; i < n; i++) {
				s[i][0] = (a[i][0] >= mid);
			}
			for (int i = 0; i < m; i++) {
				s[0][i] = (a[0][i] >= mid);
			}
			long long maxi = 0;
			for (int i = 1; i < n; i++) {
				for (int j= 1; j < m; j++) {
					if (a[i][j] >= mid) {
						s[i][j] = min(s[i - 1][j - 1], min(s[i][j - 1], s[i - 1][j])) + 1;
					} else {
						s[i][j] = 0;
					}
					
				}
			}
			for (int i = 0 ;i < n; i++) {
				for (int j = 0; j < m; j++) {
					maxi = max(maxi, s[i][j]);
				}
			}
			if (maxi >= mid) {
				low = mid + 1;
				res = max(res, mid);
			} else {
				high = mid - 1;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
