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
		int n;
		cin >> n;
		map<long long, long long> m;
		vector<vector<long long> > v(n);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				v[i].push_back(x);
				m[x]++;
			}
		}
		bool can = false;
		for (int i = 0; i < n; i++) {
			bool b = true;
			for (int j = 0; j < v[i].size(); j++) {
				if (m[v[i][j]] == 1) b = false;
			}
			if (b) can = true;
		}
		if (can) cout << "Yes" << endl;
		else cout << "No" << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
