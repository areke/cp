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
		long long n, m, a, b, c, d;
		cin >> n >> m >> a >> b >> c >> d;
		string dirs;
		cin >> dirs;
		long long dir1 = -1;
		long long dir2 = -1;
		if (dirs[0] == 'D') dir1 = 1;
		if (dirs[1] == 'R') dir2 = 1;
		bool can = true;
		set<vector<long long> > vis;
		long long res = 0;
		while (a != c || b != d) {
			//cout << a << " " << b << " " << dir1 << " " << dir2 << endl;
			if (vis.find({a, b, dir1, dir2}) != vis.end()) {
				can = false;
				break;
			}
			vis.insert({a, b, dir1, dir2});
			bool bb = false;
			if (dir1 + a > n || dir1 + a < 1) {dir1 *= -1; bb = true;}
			if (dir2 + b > m || dir2 + b < 1) {dir2 *= -1; bb = true;}
			if (bb) res++;
			a += dir1;
			b += dir2;
		}
		if (can) {
			cout << res << endl;
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
