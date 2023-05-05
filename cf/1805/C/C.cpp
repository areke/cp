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
long long BAD = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m;
		cin >> n >> m;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<long long> res(m, BAD);
		for (int i = 0; i < m; i++) {
			long long a, b, c;
			cin >> a >> b >> c;
			long long det = 4 * a * c;
			if (det < 0) {
				continue;
			}
			long long ds = sqrt(det);
			if (ds * ds < det) ds++;
			//cout << i << " " << ds << endl;
			// k > b - ds
			// k < ds + b
			auto it = lower_bound(v.begin(), v.end(), b - ds + 1);
			if (it == v.end()) continue;
			if (*it >= ds + b) continue;
			res[i] = *it;
		}
		for (int i = 0; i < m; i++) {
			if (res[i] != BAD) {
				cout << "YES" << endl;
				cout << res[i] << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		cout << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
