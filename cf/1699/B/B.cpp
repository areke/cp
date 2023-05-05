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
		vector<vector<int> > v(n, vector<int>(m, 0));

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m / 2; j++) {
				if ((i + j)  % 2 == 0) {
					v[ 2 * i][2 * j] = 0;
					v[ 2 * i + 1][2 * j] = 1;
					v[ 2 * i][2 * j + 1] = 1;
					v[ 2 * i + 1][2 * j + 1] = 0;
				} else {
					v[ 2 * i][2 * j] = 1;
					v[ 2 * i + 1][2 * j] = 0;
					v[ 2 * i][2 * j + 1] = 0;
					v[ 2 * i + 1][2 * j + 1] = 1;
				}
			}
		}
		for (int i = 0; i< n; i++) {
			for (int j = 0; j < m; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
