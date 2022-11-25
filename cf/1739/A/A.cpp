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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int> > v = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
		pair<int, int> res = make_pair(1, 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				bool b = true;
				for (int k = 0; k < v.size(); k++) {
					if (i + v[k].first >= 1 && i + v[k].first <= n && j + v[k].second >= 1 && j + v[k].second <= m) {
						b = false;
					}
				
				}
				if (b) {
					res = make_pair(i, j);
				}
			}
		}
		cout << res.first << " " << res.second << endl;
	}
	return 0;
}
