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
		vector<int> score(n, 0);
		vector<vector<int> > v(n, vector<int>(m, 0));
		int tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> v[i][j];
				score[i] += v[i][j];
				tot += v[i][j];
			}
		}
		if (tot % n != 0) {
			cout << -1 << endl;
			continue;
		}
		vector<array<int, 3> > res;
		int t = tot / n;
		for (int j = 0; j < m; j++) {
			vector<int> s;
			for (int i = 0; i < n; i++) {
				if (score[i] > t && v[i][j]) {
					s.push_back(i);
				}
			}
			for (int i = 0; i < n; i++) {
				if (score[i] < t && !s.empty() && !v[i][j]) {
					res.push_back({s.back() + 1, i + 1, j + 1});

					score[s.back()]--;
					score[i]++;
					s.pop_back();
				}
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
		}

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
