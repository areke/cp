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
		vector<vector<long long> > v(m, vector<long long>(n ,0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[j][i];
			}
		}
		for (int i = 0; i < m; i++) {
			sort(v[i].begin(), v[i].end());
		}
		long long res = 0;
		for (int i = 0; i < m; i++) {
			long long s = 0;
			for (int j = 0; j < n; j++) {
				s += v[i][j];
				res += v[i][j] * (j + 1);
				res -= s;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
