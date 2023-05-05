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
		long long n, m;
		cin >> n >> m;
		vector<vector<long long> > res(n, vector<long long>(m, 0));
		for (int i = 0; i < n; i++) {
			long long cur = (i + 1) << 16;
			for (int j = 0; j < m; j++) {
				res[i][j] = cur ^ (j + 1);
			}
		}
		cout << n * m << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << res[i][j];
				if (j == m - 1) cout << endl;
				else cout << " ";
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
