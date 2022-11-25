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
		vector<vector<bool> > v(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				v[i][j] = (s[j] == '1');
			}
		}
		vector<vector<int> > res(n);
		for (int i = 0; i < n; i++) {
			res[i].push_back(i + 1);
			for (int j = 0; j < n; j++) {
				if (v[i][j]) {
					res[j].push_back(i + 1);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i].size() << endl;
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
