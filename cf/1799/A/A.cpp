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
		set<int> s;
		vector<int> res(n, 1e9);
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			s.insert(x);
			if (s.size() <= n) {
				res[n - s.size()] = min(res[n - s.size()], i + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			if (res[i] == 1e9) cout << -1 << " ";
			else cout << res[i] << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
