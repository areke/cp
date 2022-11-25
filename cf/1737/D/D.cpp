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
 
struct loc {
	long long x, d;
	loc(long long xx, long long ww) {
		this->x = xx;
		this->d = ww;
	}
	bool operator<(const loc & l) const {
		return l.d < d;
	}
};
 
 
 
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<vector<long long> > v(n, vector<long long>(n, 1e15));
		vector<vector<long long> > d(n, vector<long long>(n, 1e15));
		for (int i = 0; i < m; i++) {
			long long ui, vi, w;
			cin >> ui >> vi >> w;
			v[ui - 1][vi - 1] = min(v[ui - 1][vi - 1], w);
			d[ui - 1][vi - 1] = 1;
			swap(ui, vi);
			v[ui - 1][vi - 1] = min(v[ui - 1][vi - 1], w);
			d[ui - 1][vi - 1] = 1;
		}
		for (int i = 0; i < n; i++) {
			d[i][i] = 0;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		long long res = 1e18;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				res = min(res, (d[0][i] + d[i][j] + d[j][n - 1]) * v[i][j]);
				for (int k = 0; k < n; k++) {
					res = min(res, (d[i][k] + d[0][k] + d[k][n - 1] + 2) * v[i][j]);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}