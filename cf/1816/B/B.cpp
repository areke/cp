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
		long long n;
		cin >> n;
		vector<vector<int> > res(2, vector<int>(n, 0));
		res[0][0] = 2 * n;
		res[1][n - 1] = 2 * n - 1;
		for (int i = 0; i < n / 2; i++) {
			res[1][2 * i] = 2 * i + 1;
			res[0][2 * i + 1] = 2 * i + 2;
		}
		for (int i = 0; i < n / 2 - 1; i++) {
			res[1][2 * i + 1] = 2 * n - (2 * i + 3);
			res[0][2 * i + 2] = 2 * n - (2 * i + 2);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cout << res[i][j];
				if (j == n - 1) cout << endl;
				else cout << " ";
			}
		}
		

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
