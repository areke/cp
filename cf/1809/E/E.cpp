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

int solve(int c, int a, int b, int t, vector<int> & v) {
	for (int i = 0; i < v.size(); i++) {
		c -= v[i];
		c = max(c, max(0, t - b));
		c = min(c, min(a, t));
	}
	return c;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<int> > res(a + 1, vector<int>(b + 1, 0));
	for (int t = 0; t <= a + b; t++) {
		int l = max(t - b, 0);
		int r = min(a, t);
		int lv = solve(l, a, b, t, v);
		int rv = solve(r, a, b, t, v);
		int low = l;
		int high = r;
		int best = lv;
		while (low <= high) {
			int mid = (low + high) / 2;
			int val = solve(mid, a, b, t, v);
			if (val == lv) {
				best = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		for (int i = l; i <= best; i++) {
			res[i][t - i] = lv;
		}
		//cout << t << " " << l << " "<< r << " " << lv << " " << rv << " " << best << endl;
		for (int i = best + 1; i <= min(r, best + (rv - lv)); i++) {
			res[i][t - i] = lv + i - best;
		}
		for (int i = best + (rv - lv) + 1; i <= r; i++) {
			res[i][t - i] = rv;
		}
		//cout << t << endl;
	}
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			cout << res[i][j];
			if (j == b) cout << endl;
			else cout << " ";
		}
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
