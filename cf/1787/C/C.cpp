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
		long long n, s;
		cin >> n >> s;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> c(n);
		vector<long long> d(n);
		vector<vector<long long> > v(2, vector<long long>(n + 5, 1e18));
		for (int i = 1; i < n - 1; i++) {
			if (2 * s > a[i] && a[i] > s) {
				c[i] = s;
				d[i] = a[i] - s;
			} else if (a[i] >= 2 * s){
				c[i] = s;
				d[i] = a[i] - s;
			} else {
				c[i] = 0;
				d[i] = a[i];
			}
			//cout << c[i] << " " << d[i] << endl;
		}
		v[0][1] = c[1] * a[0];
		v[1][1] = d[1] * a[0];
		for (int i = 2; i < n - 1; i++) {
			v[0][i] = min(v[0][i - 1] + c[i] * d[i - 1], v[1][i - 1] + c[i] * c[i - 1]);
			v[1][i] = min(v[0][i - 1] + d[i] * d[i - 1], v[1][i - 1] + d[i] * c[i - 1]);
		}
		v[0][n - 1] = a[n - 1] * c[n - 2] + v[1][n - 2];
		v[1][n - 1] = a[n - 1] * d[n - 2] + v[0][n - 2];
		long long res = min(v[0][n - 1], v[1][n - 1]);
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
