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
		int n, k;
		cin >> n >> k;
		vector<vector<int> > v(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != v[n - i - 1][n - j - 1]) cnt++;
			}
		}
		cnt /= 2;
		if (k < cnt) {
			cout << "NO" << endl;
			continue;
		}
		if (n % 2) {
			cout << "YES" << endl;
		} else {
			if ((k - cnt) % 2 == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

 	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
